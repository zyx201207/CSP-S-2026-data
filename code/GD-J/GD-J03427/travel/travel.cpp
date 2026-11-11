#include <bits/stdc++.h>
using namespace std;

char c1[10], s1[10], c2[10], s2[10];

int main (){
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	char sp;
	scanf ("%c%c", &c1[1], &c1[2]);
	scanf ("%c", &sp);
	scanf ("%c%c%c", &s1[1], &s1[2], &s1[3]);
	scanf ("%c", &sp);
	scanf ("%c%c", &c2[1], &c2[2]);
	scanf ("%c", &sp);
	scanf ("%c%c%c", &s2[1], &s2[2], &s2[3]);
	if (c1[1] == c2[1] && c1[2] == c2[2]){
		if (s1[1] == s2[1] && s1[2] == s2[2]){
			if ((s1[3] < 'D' && s2[3] < 'D') || (s1[3] > 'C' && s2[3] > 'C')){
				int a = s1[3], b = s2[3];
				if (abs (a - b) == 1)
					printf ("1111");
				else
					printf ("1110");
			}
			else
				printf ("1100");
		}
		else
			printf ("1000");
	}
	else
		printf ("0000");
	return 0;
}
