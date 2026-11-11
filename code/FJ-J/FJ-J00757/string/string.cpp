#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+5;
int n, a[maxn], ans=0;
char c[maxn];
string s = "";
signed main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cin >> c[i];
		for (int j = 1; j <= a[i]; j++)
			s += c[i];
	} int f = s.size();
	for (int i = 0; i < f/2; i++) {
		if (s[i] != s[f-i-1]) {
			ans++;
		}
	}return cout << ans, 0;
}
