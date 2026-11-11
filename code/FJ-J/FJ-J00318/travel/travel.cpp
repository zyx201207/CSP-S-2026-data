#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e2 + 10;
char c1[N], s1[N], c2[N], s2[N];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	scanf("%s %s %s %s", &c1, &s1, &c2, &s2);
	
	if (c1[0] == c2[0] && c1[1] == c2[1]) {
		printf("1");
		
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			printf("1");
			
			if (((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'))) {
				printf("1");
				
				if (abs(s1[2] - s2[2]) == 1) {
					printf("1");
				} else {
					printf("0");
				}
			} else if (((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F'))) {
				printf("11");
			} else {
				printf("00");
			}
		} else {
			printf("000");
		}
	} else {
		printf("0000");
	}
	return 0;
}
