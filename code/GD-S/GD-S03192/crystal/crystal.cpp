#include <bits/stdc++.h>
#define ll long long
#define PII pair<int, int>
#define vi vector<int>
#define i128 __int128
using namespace std;
const int maxn = 5e5 + 5;
int n;
ll m, a[maxn], s[maxn];
bool check(int x)
{
	for(int i = x; i <= n; i++)
	{
		if(a[i] * x - (s[i] - s[i - x]) <= m) return true;
	}
	return false;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i]; 
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	int l = 1, r = n, ans = 0;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << '\n';
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
