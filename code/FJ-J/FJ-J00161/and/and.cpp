#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m; long long ans = 0, a[N];
bool cur[N], vis[N];

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	
	for (int i = 29; i >= 0; i --)
	{
		int ok = 0;
		memset(cur, false, sizeof cur);
		for (int j = 1; j <= n; j ++)
		{
			if (vis[j]) continue;
			
			if (!(a[j] & (1 << i))) cur[j] = true;
			else ok ++;			
		}

			
		if (ok >= m)
		{
			for (int j = 1; j <= n; j ++)
				if (cur[j])
					vis[j] = true;
			ans += (1ll << i);
		}
	}
	cout << ans << "\n";
	return 0;
} 
//3 :  0011
//15 : 1111
//12 : 1100
//12 : 1100
