#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], ans;
bool vis[200005];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++) cin>>a[i];
	sort(a + 1, a + n + 1);
	ans = a[n];
	vis[n] = 1;
	for(int i = 2; i <= m; i++)
	{
		int mx = 0, mxn;
		for(int j = 1; j <= n; j++)
		{
			if(vis[j]) continue;
			if(ans & a[j] > mx)
			{
				mx = ans & a[j];
				mxn = j;
			}
		}
		ans &= a[mxn];
		vis[mxn] = 1;
	}
	cout<<ans<<'\n';
	return 0;
}
