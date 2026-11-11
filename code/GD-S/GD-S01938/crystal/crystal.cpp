#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
long long ss[MAXN],pre[MAXN],m;
inline int solve(int i)
{
	int l = 1,r = i,mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (ss[i] * (i - mid + 1) - (pre[i] - pre[mid - 1]) <= m) r = mid - 1;
		else l = mid + 1;
	}
	return r + 1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> ss[i];
	sort(ss + 1,ss + n + 1);
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + ss[i];
	for (int i = 1; i <= n; i++) ans = max(ans,i - solve(i) + 1);
	cout << ans << '\n';
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
