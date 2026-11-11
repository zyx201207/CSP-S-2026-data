#include<bits/stdc++.h>
using namespace std;
long long c1, s1, c2, s2;
char S1, S2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%lld%lld %c%lld%lld %c", &c1, &s1, &S1, &c2, &s2, &S2);
		//cout << c1 << " " << s1 << S1 << " " << c2 << " " << s2 <<S2;
	if(c1 == c2) {
		printf("1");
	} else {
		printf("0000");
		return 0;
	}
	if(s1 == s2) {
		printf("1");
		if((S1 == 'A' && S2 == 'B') || (S2 == 'A' && S1 == 'B')) {
			printf("11");
		} else if((S1 == 'A' && S2 == 'C') || (S2 == 'A' && S1 == 'C')) {
			printf("10");
		} else if((S1 == 'B' && S2 == 'C') || (S2 == 'B' && S1 == 'C')) {
			printf("11");
		} else if((S1 == 'D' && S2 == 'F') || (S2 == 'F' && S1 == 'D')) {
			printf("11");
		} else {
			printf("00");
		}
	} else {
		printf("000");
	}
	return 0;
}
