#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10,M=510;
int a[M][N],f[M][N],t[M][N],b[N],w[N];
int c,n,m,d,q,sum;
vector<ll> e[N];
int read()
{
	int f=1,s=0;
	char ch=getchar();
	while (!isdigit(ch))
	{
		if (ch=='-')
		{
			f=-1;
		}
		ch=getchar();
	}
	while (isdigit(ch))
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return f*s;
}
void dfs(int u,int x,int ans,int to,int op)
{
	if (u==0)
	{
		return ;
	}
	if (b[x])
	{
		sum=min(sum,ans+t[x][to]);
		return ;
	}
	for (int i=0; i<e[u].size(); i++)
	{
		int v=e[u][i];
		if (v==x)
		{
			if (op)
			{
				dfs(a[x][u],x,ans,to,1);
				continue;
			}
			dfs(f[x][u],x,ans,to,0);
			continue;
		}
		dfs(a[v][u],v,ans+t[x][u]+t[v][u],to,1);
		dfs(f[v][u],v,ans+t[x][u]+t[v][u],to,0);
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for (int i=1; i<=m; i++)
	{
		w[i]=read();
	}
	for (int i=1; i<=n; i++)
	{
		int k=read();
		int up=0;
		for (int j=1; j<=k; j++)
		{
			int x=read();
			a[i][up]=x;
			f[i][x]=up;
			up=x;
			e[x].push_back(i);
			t[i][x]=read();
		}
		a[i][up]=0;
	}
	while (q--)
	{
		int u=read();
		int v=read();
		for (int i=0; i<e[v].size(); i++)
		{
			b[e[v][i]]++;
		}
		sum=INT_MAX;
		for (int i=0; i<e[u].size(); i++)
		{
			int p=e[u][i];
			dfs(u,p,t[p][u],v,1);
			dfs(u,p,t[p][u],v,0);
		}
		printf("%d\n",sum+w[u]+w[v]);
		for (int i=0; i<e[v].size(); i++)
		{
			b[e[v][i]]=0;
		}
	}
	return 0;
}
