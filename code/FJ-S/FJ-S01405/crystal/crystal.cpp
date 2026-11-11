#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans;
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
	}
	sort(a+1,a+n+1);
	for(int r=1,l=0,s=0;r<=n;r++,s+=((a[r]-a[r-1])*(r-l-1)))
	{
		while(l<r)
		{
			if(s<=m)break;
			l++,s-=(a[r]-a[l]);
		}
		ans=max(ans,r-l);
	}
	cout<<ans;
	return 0;
}

