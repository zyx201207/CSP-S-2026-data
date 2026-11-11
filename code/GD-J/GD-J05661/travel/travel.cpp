#include <stdio.h>
#define abs(a) (((a) >= 0) ? (a) : (-(a)))
int c1, c2, row_1, row_2, col_1, col_2;
char s1[5], s2[5];
int main (void) {
	FILE *inf = fopen ("travel.in", "r");
	FILE *outf = fopen ("travel.out", "w");
	
	fscanf (inf, "%02d %s %02d %s", &c1, s1, &c2, s2);
	row_1 = (s1[0] - '0') * 10 + s1[1] - '0';
	row_2 = (s2[0] - '0') * 10 + s2[1] - '0';
	col_1 = s1[2] - 'A' + (s1[2] != 'F');
	col_2 = s2[2] - 'A' + (s2[2] != 'F');
	
	int sign = (c1 == c2);
	if (sign)	fputc ('1', outf);
	else		fputc ('0', outf);
	sign &= (row_1 == row_2);
	if (sign)	fputc ('1', outf);
	else		fputc ('0', outf);
	sign &= (!((col_1 > 3) ^ (col_2 > 3)));
	if (sign)	fputc ('1', outf);
	else		fputc ('0', outf);
	sign &= (abs (col_1 - col_2) == 1);
	if (sign)	fputc ('1', outf);
	else		fputc ('0', outf);
	
	fclose (inf);
	fclose (outf);
	return 0;
}
