#include<bits/stdc++.h>
using namespace std;

char c1[10], s1[10], c2[10], s2[10];

int main () {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%s%s%s%s", c1 + 1, s1 + 1, c2 + 1, s2 + 1);
	int a1 = (c1[1] - '0') * 10 + (c1[2] - '0');
	int a2 = (c2[1] - '0') * 10 + (c2[2] - '0');
	if(a1 == a2){
		printf("1");
		int b1 = (s1[1] - '0') * 10 + (s1[2] - '0');
		int b2 = (s2[1] - '0') * 10 + (s2[2] - '0');
		if(b1 == b2){
			printf("1");
			char x1 = s1[3];
			char x2 = s2[3];
			if(((x1 == 'A' && x2 == 'B') || (x1 == 'A' && x2 == 'C') || (x1 == 'B' && x2 == 'C') || (x1 == 'D' && x2 == 'F')) || ((x2 == 'A' && x1 == 'B') || (x2 == 'A' && x1 == 'C') || (x2 == 'B' && x1 == 'C') || (x2 == 'D' && x1 == 'F')))
				printf("1");
			else
				printf("0");
			if(((x1 == 'A' && x2 == 'B') || (x1 == 'B' && x2 == 'C') || (x1 == 'D' && x2 == 'F')) || ((x2 == 'A' && x1 == 'B') || (x2 == 'B' && x1 == 'C') || (x2 == 'D' && x1 == 'F')))
				printf("1");
			else
				printf("0");
		}
		else
			printf("000");
	}
	else
		printf("0000");
	return 0;
} 
