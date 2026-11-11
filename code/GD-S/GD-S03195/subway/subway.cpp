#include<bits/stdc++.h> 
using namespace std;
long long id[505][100005];
long long id1[505][100005];
long long w[100005];
long long k[505][100005];
int start[100005];
long long endi[100005];
long long ans=1e9+5;
long long ans1;
long long c,n,m,d,q;
void dfs(int a,int b,int t)
{
	if(b==endi[q])
	{
		ans1+=w[endi[q]];
		ans=min(ans,ans1);
		return;
	}
	else
	{
		cout<<0;
		dfs(a,id1[a][++t],t++);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(id1[i][j]==b and a!=i)
				{
					ans1+=k[i][b];
					ans+=k[a][b];
					dfs(i,b,id[i][b]);
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int j=1;j<=n;j++)
	{
		int k1=0;
		cin>>k1;
		for(int i=1;i<=2*k1;i++)
		{
			int x,y;
			id1[j][i]=x;
			id[j][x]=i;
			k[j][x]=y;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		start[i]==x;
		endi[i]==y;
	}
	while(q--)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;i++)
			{
				if(id1[i][j]==start[q])
				{
					ans1+=k[i][start[q]];
					dfs(i,start[q],j);
					cout<<0;
					ans1=0;
				}
			}
		}
		cout<<ans;
		ans=0;
	}
}
