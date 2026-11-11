//travel
#include <stdio.h>
int c1, c2, column1, column2;
char s1, s2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d %d%c %d %d%c", &c1, &column1, &s1, &c2, &column2, &s2);
	if(c1 == c2) {
		printf("1");
		if(column1 == column2) {
			printf("1");
			if(s1 <= 'C' && s1 >= 'A') {
				if(s2 <= 'C' && s2 >= 'A') {
					printf("1");
					if(s1 + 1 == s2 || s2 + 1 == s1) {
						printf("1");
					}
					else {
						printf("0");
					}
				}
				else {
					printf("00");
				}
			}
			else if(s1 <= 'E' && s1 >= 'D') {
				if(s2 <= 'E' && s2 >= 'D') {
					printf("1");
					if(s1 + 1 == s2 || s2 + 1 == s1) {
						printf("1");
					}
					else {
						printf("0");
					}
				}
				else {
					printf("00");
				}
			}
			else {
				printf("00");
			}
		}
		else {
			printf("000");
		}
	}
	else {
		printf("0000");
	}
	printf("\n"); 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
