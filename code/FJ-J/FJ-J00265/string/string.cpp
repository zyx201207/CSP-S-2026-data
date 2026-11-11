#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n, L, ans; struct node { int a; char c; } a[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string s = "", t = "";
	cin >> n; for (int i = 1; i <= n; i++) { cin >> a[i].a >> a[i].c; for (int j = 1; j <= a[i].a; j++) s += a[i].c; }
	t = s; reverse(t.begin(), t.end());
	int ans = 0;
	for (int i = 0; i < s.size(); i++) if (s[i] != t[i]) ans++; 
	cout << (ans >> 1) << '\n';
	return 0;
}
