#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans = LLONG_MIN,a[500005],d[500005],mn = LLONG_MAX,mx = LLONG_MIN;
bool fl;
inline int run(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(a[i] > x) d[i] = LLONG_MAX;
		else d[i] = x - a[i];
	}
	sort(d+1,d+n+1);
	int cnt = m,res = 0;
	for(int i=1;i<=n;i++)
	{
		if(cnt >= d[i])
		{
			cnt -= d[i];
			res++;
			if(cnt == 0) break;
		}
		else break;
	}
	return res;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx = max(mx,a[i]);
		mn = min(mn,a[i]);
		if(abs(a[i]) > 100) fl = 1;
	}
	if(fl)
	{
		cout<<run(mx)<<"\n";
		return 0;
	}
	for(int i=mn;i<=mx;i++) ans = max(ans,run(i));
	cout<<ans<<"\n";
	return 0;
}