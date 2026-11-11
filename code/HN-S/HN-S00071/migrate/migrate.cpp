#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c, t, n, d;
int a[5005],cnt[5005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++)
		{
			int x = a[1], ans = 0;
			for (int j = 1; j <= i; j++)
			{
				if (a[j] - x > d){
					x = j-1;
					ans++;
				}
			}
			cnt[i] = ans + 1;
		}
		int maxn = INT_MIN, ans = 0;
		for (int i = 1; i <= n; i++)
		{
			maxn = max(maxn, cnt[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			if (cnt[i] == maxn)
			{
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

