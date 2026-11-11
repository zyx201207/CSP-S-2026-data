#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],pre[500005],ans;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		pre[i] = pre[i-1] + a[i];
	}
	int cur = 1;
	for(int i = 1; i <= n; i++)
	{
		while(cur < i && (i-cur+1) * a[i] - (pre[i] - pre[cur-1]) > m) cur++;
		ans = max(ans,i-cur+1);
	}
	cout << ans << '\n';
	return 0;
}
