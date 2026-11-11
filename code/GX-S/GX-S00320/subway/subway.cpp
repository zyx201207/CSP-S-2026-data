#include <bits/stdc++.h>
using namespace std;

const int N=505,N1=1e5+5;
const long long M=999999999999999999;
int bianhao,n,m,d,q,v[N],zd[21],tim[21];
long long e[N][N];

void ac()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(k==i)	continue;
			for(int j=1;j<=n;j++)
			{
				if(k==i || i==j)	continue;
				long long sum=e[i][k]+e[k][j];
				if(e[i][k]!=M && e[k][j]!=M && e[i][j]>sum)	e[i][j]=e[j][i]=sum;
			}
		}
	}
}

struct edge{
	int to,w;
};
vector<edge> e1[N1];
int ans=1e6;
bool vis[N1];
void dfs(int x,int mb,int len)
{
	vis[x]=1;
	if(x==mb)
	{
		ans=min(ans,len);
		return;
	}
	for(edge to : e1[x])
	{
		if(!vis[to.to])	
		{
			dfs(to.to,mb,len+1);
			vis[to.to]=0;
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>bianhao>>m>>n>>d>>q;
	if(n<501)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(i==j)	e[i][j]=e[j][i]=0;
				else	e[i][j]=e[j][i]=M;
			}
		}
		for(int i=1;i<=n;i++)	cin>>v[i];
	
		for(int i=1;i<=m;i++)
		{
			int k;
			cin>>k;
			for(int j=1;j<=k;j++)	cin>>zd[j]>>tim[j];
			for(int j=1;j<k;j++)
			{
				for(int t=j+1;t<=k;t++)	
				{
					if(e[zd[j]][zd[t]]>tim[zd[j]]+tim[zd[t]])	e[zd[j]][zd[t]]=e[zd[t]][zd[j]]=tim[j]+tim[t];
				}
			}
		}
	
		ac();
		for(int i=1;i<=q;i++)
		{
			int fr,to;
			cin>>fr>>to;
			cout<<e[fr][to]+v[fr]+v[to]<<'\n';
		}
	}
	else if(12<=bianhao && bianhao<=19)
	{
		for(int i=1;i<=n;i++)	cin>>v[i];
		for(int i=1;i<=m;i++)
		{
			int k;
			cin>>k;
			for(int j=1;j<=k;j++)	cin>>zd[j]>>tim[j];
			for(int j=1;j<k;j++)
			{
				for(int t=j+1;t<=k;t++)	
				{
					e1[zd[j]].push_back({zd[t],tim[j]+tim[t]});
					e1[zd[t]].push_back({zd[j],tim[j]+tim[t]});
				}
			}
		}
		for(int i=1;i<=q;i++)
		{
			int fr,to;
			cin>>fr>>to;
			memset(vis,0,sizeof(vis));
			dfs(fr,to,0);
			cout<<1ll*ans*e1[fr][1].w<<endl;
		}
	}

	return 0;
}
