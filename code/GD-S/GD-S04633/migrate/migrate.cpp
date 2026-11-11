#include<bits/stdc++.h>
using namespace std;
long long n,d,a[5050];
long long f[5050],dis[5050];
int check(int u,int v)
{
	long long f[5050],dis[5050];
	memset(dis,0x3f,sizeof dis);
	f[u]=1,dis[u]=0;
	for(int i=u;i<=v;i++)
	{
		for(int j=i+1;j<=v;j++)
		{
			if(a[j]-a[i]<=d)
			{
				if(dis[j]>dis[i]+1)
				{
					dis[j]=dis[i]+1;
					f[j]=f[i];
				}
				else if(dis[j]==dis[i]+1)
				{
					f[j]+=f[i];
				}
			}
		}
	}
	return f[v]==2;
}
void solve()
{
	int ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)ans+=check(i,j);
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
 } 
