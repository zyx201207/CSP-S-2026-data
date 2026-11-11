#include<iostream>
#include<string>
using namespace std;
using ll = int;
string s[2], s2[2];
bool vis[4];
ll check(char c) {return (c - '0');}
void solve() {
	cin >> s[0] >> s[1] >> s2[0] >> s2[1];
	ll A = check(s[0][0]) * 10 + check(s[0][1]);
	ll B = check(s2[0][0]) * 10 + check(s2[0][1]);
	vis[0] = (A == B);
	A = check(s[1][0]) * 10 + check(s[1][1]), B = check(s2[1][0]) * 10 + check(s2[1][1]);
	vis[1] = (vis[0] && (A == B));
	ll C = (s[1][2] - 'A'), D = (s2[1][2] - 'A');
	vis[2] = (vis[1] && ((C <= 2 && D <= 2) || (C > 2 && D > 2)));
	if (vis[2]) vis[3] = ((C == D + 1) || (D == C + 1));
	for (ll i = 0;i < 4;++i) cout << vis[i];
	cout << '\n'; 
	return;
} 
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll _ = 1;
//	cin >> _;
	while (_--) {
		solve();
	}
}
