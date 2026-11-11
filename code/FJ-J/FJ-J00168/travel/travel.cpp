#include<bits/stdc++.h>
using namespace std;

const int N = 20;
char sa[N];
char sb[N];
char sc[N];
char sd[N];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%s %s %s %s", sa, sb, sc, sd);
	if (sa[0] == sc[0] && sa[1] == sc[1]) {
		if (sb[0] == sd[0] && sb[1] == sd[1]) {
			if ((sb[2] <= 'C' && sd[2] <= 'C') || (sb[2] > 'C' && sd[2] > 'C')) {
				if ((min(sb[2], sd[2]) == 'A' && max(sb[2], sd[2]) == 'B') || (min(sb[2], sd[2]) == 'B' && max(sb[2], sd[2]) == 'C') || (min(sb[2], sd[2]) == 'D' && max(sb[2], sd[2]) == 'F')) {
					cout << "1111";
				} else {
					cout << "1110";
				}
			} else {
				cout << "1100";
			}
		} else {
			cout << "1000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}
