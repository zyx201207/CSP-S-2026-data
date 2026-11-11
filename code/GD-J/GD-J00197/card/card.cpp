#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[500005];
int nxt[500005];
int now[300005];
int ans[300005];
string s[500005];
string together(string x,string y)
{
	string ss;
	for(int i = 0; i < x.size(); i++) {
		if(x[i] == '1') {
			ss += '1';
		}
		else if(y[i] == '1') {
			ss += '1';
		}
		else ss += '0'; 
	}
	return ss;
}
string init;
signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out ","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		nxt[now[a[i]]] = i;
		now[a[i]] = i;
	}
	for(int i = 1; i <= n + 1; i++) {
		init += '0';
	}
	for(int i = 1; i <= n; i++) {
		s[i] = init;
	}
	for(int i = n; i >= 1; i--) {
		for(int j = i; j <= n; j++) {
			if(nxt[j] == 0) {
				s[i][j] = '1'; 
			}
			else {
				s[i] = together(s[i],s[nxt[j]]);
				break;
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < s[i].size(); j++) {
			ans[a[j]] += s[i][j] - '0';
		}
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
