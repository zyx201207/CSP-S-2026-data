#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[5005],mi=LONG_LONG_MAX,sum=0,ans;
void dfs(int ed,int lg,int nw)
{
	if(lg>mi)return;
	if(nw==ed)
	{
		if(lg==mi)sum++;
		else if(lg<mi)
		{
			mi=lg;
			sum=1;
		}
		return;
	}
	for(int i=ed;i>nw;i--)
	{
		if(abs(a[i]-a[nw])<=d)
		{
			dfs(ed,lg+1,i);
		}
	}
	return;
}
signed main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				dfs(j,0,i);
				if(sum==2)ans++;
				sum=0,mi=LONG_LONG_MAX;
			}
		}
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}
