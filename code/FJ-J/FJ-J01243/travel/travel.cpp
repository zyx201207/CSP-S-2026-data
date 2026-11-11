#include <bits/stdc++.h>
#define ll long long

using namespace std;

string C_1, S_1, C_2, S_2;

string pai1, pai2;
char zuo1, zuo2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> C_1 >> S_1 >> C_2 >> S_2;
	if (C_1 == C_2) {
		printf("1");
		pai1 = S_1[0] + S_1[1];
		pai2 = S_2[0] + S_2[1];
		zuo1 = min(S_1[2], S_2[2]);
		zuo2 = S_1[2] + S_2[2] - zuo1;
		if (pai1 == pai2) {
			printf("1");
			if (zuo1 <= 'C' && zuo2 >= 'D') {
				printf("00");
			}
			else {
				printf("1");
				if ((zuo1 == 'D' && zuo2 == 'F') || ((int)(zuo2 - zuo1) == 1))
					printf("1");
				else
					printf("0");
			}
		}
		else
			printf("000");
	}
	else
		printf("0000");
	return 0;
}

