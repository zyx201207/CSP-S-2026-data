#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define INF 0x3f3f3f3f
ll n,m;
ll num[500010];
int ans = 1;
ll pre[500010];
int erfen(int l,int r,int x)
{
	int ans = 0;
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		int p = x - mid;
		if(num[x]*mid - pre[x] + pre[p] <= m)
		{
			ans = max(ans,mid);
			l = mid + 1;
		}
		else r = mid - 1; 
	}
	return ans;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++) cin >> num[i];
	sort(num+1,num+n+1);
	for(int i = 1;i<=n;i++) 
	{
		pre[i] = pre[i-1] + num[i];
		ans = max(ans,erfen(1,i,i));
	}
	cout << ans;
	return 0;
} 
