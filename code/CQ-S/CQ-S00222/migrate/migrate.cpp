#include<bits/stdc++.h>
using namespace std;
const int N=2e2+1;
int c,t,a[N],dp[N],n,d,ans;
bool b[N];
void dfs2(int x,int j)
{
	if(x==j)
	{
		ans++;
		return;
	}
	bool f=0;
	for(int i=1;i<=x;i++)
		if(b[i]==0)
			f=1;
	if(!f) return;
	for(int i=1;i<=j;i++)
	{
		if(b[i]==0 && a[i]-a[x]<=d)
		{
			b[i]=1;
			dfs2(i,j);
		}
	}
}
void dfs1(int x,int j)
{
	for(int i=1;i<=j;i++)
	{
		if(b[i]==0 && a[i]-a[x]<=d)
		{
			b[i]=1;
			dfs1(i,j);
			b[i]=0;
		}
	}
	
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		memset(b,0,sizeof(b));
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=2;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				dfs1(i,j);
				dfs2(i,j);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
