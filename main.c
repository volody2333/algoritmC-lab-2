#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <direct.h>

int isVowel(char c) {
	char lower = tolower(c);
	return (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u');
}
int isConsonant(char c) {
	return isalpha(c) && !isVowel(c);
}

int main() {
	char filename[100];
	FILE *file;
	int ch;
	
	int total_chars = 0;
	int lines = 0;
	int digits = 0;
	int punctuation = 0;
	int spaces = 0;
	int letters = 0;
	int lowercase = 0;
	int uppercase = 0;
	int vowels = 0;
	int consonants = 0;
	
	printf("Enter the file name to be analyzed:");
	scanf("%99s", filename);
	file = fopen(filename, "r");
	
	if (file == NULL) {
		printf("Error: failed to open file '%s'\n", filename);
		printf("Check:\n");
		printf("1. Does the file exist\n");
		printf("2. Is the file name specified correctly\n");
		printf("3. Do you have permission to read the file\n");
		return 1;
	}
printf("File '%s' successfully opened. Starting analysis...\n\n", filename);

while ((ch = fgetc(file)) != EOF) {
	total_chars++;
	if (ch == '\n') {
		lines++;
	}
	if (isdigit(ch)) {
		digits++;
	}
	if (ispunct(ch)) {
		punctuation++;
	}
	if (isspace(ch)) {
		spaces++;
	}
	if (islower(ch)) {
		lowercase++;
		letters++;
	} else if (isupper(ch)) {
		uppercase++;
		letters++;
	}
	if (isVowel(ch)) {
		vowels++;
	} else if (isConsonant(ch)) {
		consonants++;
	}
	}

fclose(file);
printf("Analysis completed.\n\n");
printf("=====================\n");
printf("File result: %s\n", filename);
printf("=====================\n");

printf("Total numbers of characters: %d\n", total_chars);
printf("Number of lines: %d\n", lines + 1);
printf("Digits: %d\n", digits);
printf("Punctuation marks: %d\n", punctuation);
printf("Whitespace characters: %d\n", spaces);
printf("Letters: %d\n", letters);
printf("Lowercase letters: %d\n", lowercase);
printf("Uppercase letters: %d\n", uppercase);
printf("Vowels letters: %d\n", vowels);
printf("Consonants letters: %d\n", consonants);
printf("=====================\n");

if (letters > 0) {
	printf("\nAdditional statistics:\n");
	printf("Ratio vowel/consonant: %.1f%% / %.1f%%\n",
	       (vowels * 100.0) / letters,
	       (consonants * 100.0) / letters);
	printf("Lowercase/uppercase letters: %.1f%% / %.1f%%\n",
	       (lowercase * 100.0) / letters,
		   (uppercase * 100.0) / letters);
}
printf("\nText information:\n");
printf("File size: ~%d bytes\n", total_chars);
printf("Average line length: %.1f characters\n",
       total_chars / (float)(lines + 1));
	
	return 0;
}
