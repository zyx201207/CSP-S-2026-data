#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int INF = 0x3f3f3f3f;
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, c1, s2, c2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2) return cout << "0000\n", 0;
	else {
		cout << 1;
		if(s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << 1;
			int n1 = s1[2], n2 = s2[2];
			bool flag = 0;
			if(n1 == 'A' || n1 == 'B' || n1 == 'C') {
				if(n2 == 'A' || n2 == 'B' || n2 == 'C') {
					flag = 1;
				}
			}
			else {
				if(n2 == 'D' || n2 == 'F') {
					flag = 1;
				} 
			}
			
			if(flag == 1) {
				cout << 1;
				bool f = 0;
				if(n1 == 'A') {
					if(n2 == 'B') f = 1;
				}
				else if(n1 == 'B') {
					if(n2 == 'A' || n2 == 'C') f = 1;
				}
				else if(n1 == 'C') {
					if(n2 == 'B') f = 1;
				}
				else if(n1 == 'D') {
					if(n2 == 'F') f = 1;
				}
				else if(n1 == 'F') {
					if(n2 == 'D') f = 1;
				}
				cout << f << '\n';
			}
			else return cout << "00\n", 0;
		}
		else return cout << "000\n", 0;
	}
	return 0;
} 
