#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
string c1, s1, c2, s2;
string a1, b1;
char a2, b2;
int fa, fb;
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	for(int i = 0; i < 2; i++) {
		a1 += s1[i];
		b1 += s2[i];
	}
	a2 = s1[2], b2 = s2[2];
	if(a2 == 'A' || a2 == 'B' || a2 == 'C') fa = 1;
	else fa = 2;
	if(b2 == 'A' || b2 == 'B' || b2 == 'C') fb = 1;
	else fb = 2;
	if(c1 == c2) {
		cout << 1;
		if(a1 == b1) {
			cout << 1;
			if(fa == fb) {
				cout << 1;
				if(a2 + 1 == b2 || b2 + 1 == a2) {
					cout << 1;
				}
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
} 
