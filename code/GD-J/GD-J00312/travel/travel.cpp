#include <bits/stdc++.h>
using namespace std;
char c1[5], c2[5], c3[5], c4[5];
int main () {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);	
	scanf("%s%s%s%s", c1 + 1, c2 + 1, c3 + 1, c4 + 1);
	if (c1[1] == c3[1] && c1[2] == c3[2]) { 
		printf("1");
		if (c2[1] == c4[1] && c2[2] == c4[2]) {
			printf("1");
			int a = c2[3] - 'C', b = c4[3] - 'C';
			if ((a > 0 && b > 0) || (a <= 0 && b <= 0)) {
				printf("1");
				int c = (c2[1] - '0') * 10 + c2[2], 
					d = (c4[1] - '0') * 10 + c4[2];
				if (abs(c - d) < 2 && abs(a - b) < 2) {
					if (abs(c - d) == 2 && abs(a - b) == 2)
						printf("0");
					else printf("1");
				} else printf("0");   
			} else printf("00");	 
		} else printf("000");
	} 
	else printf("0000");
	
} 
