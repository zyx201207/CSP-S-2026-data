#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;
ll x[N];
int w[5010][5010];
bool vis[5010];
int cnt[5010][5010];
int f[5010][5010];
int a[5010];
int b[10010][3];
int tot=0;
void addedge(int x,int y)
{
	tot++;
	b[tot][1]=y;
	b[tot][2]=a[x];
	a[x]=tot;
}
void dfs(int x,int y,int step)
{
	if (x==y)
	{
		if (step<f[x][y])
		{
			f[x][y]=step;
			cnt[x][y]=1;
		}
		else
		{
			if (step==f[x][y])
			{
				cnt[x][y]++;
			}
		}
		return ;
	}
	for (int i=a[x];i>0;i=b[i][2])
	{
		int v=b[i][1];
		if (vis[v]==1)
			continue;
		vis[v]=1;
		dfs(v,y,step+1);
		vis[v]=0;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(f,0x3f3f3f3f,sizeof(f));
	int c,t;
	cin>>c>>t;
	while (t--)
	{
		int n;
		ll ans=0;
		ll d;
		cin>>n>>d;
		for (int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if (c<=10)
		{
			for (int i=1;i<=n;i++)
			{
				for (int j=i+1;j<=n;j++)
				{
					if (abs(x[i]-x[j])<=d)
					{
						addedge(i,j);
						addedge(j,i);
					}
				}
			}
			for (int i=1;i<=n;i++)
			{
				for (int j=1;j<=n;j++)
				{
					dfs(i,j,0);
					if (cnt[i][j]==2)
					{
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;	
} 
