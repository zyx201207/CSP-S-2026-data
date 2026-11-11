#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,ans=0,a[2000005],dis[2000005],f[2000005];
void js(int x)
{
	f[x]=1;
	dis[x]=0;
	for(int i=x;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]-a[i]>d)break;
			if(dis[i]+1<=dis[j])
			{
				dis[j]=dis[i]+1;
				f[j]+=f[i];
			}
		}
		if(f[i]==2)ans++;
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[j]=INT_MAX;
				f[j]=0;
			}
			js(i);
		}
		cout<<ans<<'\n';
	}
	return 0;
}

