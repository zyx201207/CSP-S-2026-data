#include<bits/stdc++.h>
using namespace std;

int c1, c2;
char s1[10], s2[10];

int main(){
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	scanf("%d%s%d%s", &c1, s1 + 1, &c2, s2 + 1);
	if (c1 == c2)
		printf("1");
	else{
		printf("0000");
		return 0;
	}
	if ((s1[1] - '0') * 10 + s1[2] - '0' == (s2[1] - '0') * 10 + s2[2] - '0')
		printf("1");
	else{
		printf("000");
		return 0;
	}
	if (s1[3] == 'A' || s1[3] == 'B' || s1[3] == 'C' && s2[3] != 'D' && s2[3] != 'F')
		printf("1");
	else
		if (s1[3] != 'A' && s1[3] != 'B' && s1[3] != 'C' && s2[3] == 'D' || s2[3] == 'F')
			printf("1");
		else{
			printf("00");
			return 0;
		}
	if (s1[3] != 'F' && s2[3] != 'F' && s1[3] != 'D' && s2[3] != 'D')
		if (s1[3] - s2[3] == 1 || s2[3] - s1[3] == 1)
			printf("1");
		else
			printf("0");
	else
		if (s1[3] == 'F' && s2[3] == 'D')
			printf("1");
		else
			if (s1[3] == 'D' && s2[3] == 'F')
				printf("1");
			else
				printf("0");
	
	return 0;
}
