#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000010;
int c,t,n,vis[N],mnstp=N;
ll d,x[N],res=0,st=0;
void dfs(int u,int tg,int stp)
{
	if (u==tg)
	{
		mnstp=min(mnstp,stp);
		return ;
	}
	for (int i=1;i<=n;i++)
	{
		if (!vis[i]&&d>=abs(x[u]-x[i]))
		{
			vis[i]=1;
			dfs(i,tg,stp+1);
			vis[i]=0;
		}
	}
}
void dfs2(int u,int tg,int stp)
{
	if (u==tg)
	{
		if (stp==mnstp) st++;
		return ;
	}
	for (int i=1;i<=n;i++)
	{
		if (!vis[i]&&d>=abs(x[u]-x[i]))
		{
			vis[i]=1;
			dfs2(i,tg,stp+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while (t--)
	{
		res=0;
		cin>>n>>d;
		for (int i=1;i<=n;i++) cin>>x[i];
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				memset(vis,0,sizeof(vis));
				st=0;
				mnstp=N;
				vis[i]=1;
				dfs(i,j,0);
				memset(vis,0,sizeof(vis));
				vis[i]=1;
				dfs2(i,j,0);
				vis[i]=0;
				if (st==2)
				{
					res++;
				}
			}
		}
		cout<<res/2<<'\n';
	}
	return 0;
}


