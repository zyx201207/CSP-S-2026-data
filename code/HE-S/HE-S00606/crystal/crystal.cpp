#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],s[500005],ans,res,cnt;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int l=1;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		while(l<i&&ans*(a[i]-a[i-1])+res>m)
		{
			res-=a[i-1]-a[l];
			ans--;l++;
		}
		if(ans*(a[i]-a[i-1])+res<=m)
		{
			res+=ans*(a[i]-a[i-1]);
			ans++;
			cnt=max(ans,cnt);
		}
	}
	cout<<cnt;
	return 0;
} 
