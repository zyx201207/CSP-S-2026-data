#include<bits/stdc++.h>
using namespace std;
const int N=5e6+1,M=5e3+1;
int h[N],cnt,w[M],dis[N],vis[N],c,n,m,o,r,k[M],x[M],y[M],t[M][M],t1[M],st,ed,f[M];
struct edge{
	int to,next,d;
}e[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
void add(int u,int v,int d)
{
	e[++cnt].to=v;
	e[cnt].d=d;
	e[cnt].next=h[u];
	h[u]=cnt;
}
void dj(int a)
{
	dis[a]=0;
	q.push({0,a});
	while(!q.empty())
	{
		int k=q.top().second;
		q.pop();
		if(vis[k]==1)
			continue;
		vis[k]=1;
		for(int i=h[k];i;i=e[i].next)
		{
			if(!vis[e[i].to]&&dis[k]+e[i].d<dis[e[i].to])
			{
				dis[e[i].to]=dis[k]+e[i].d;
				q.push({dis[e[i].to],e[i].to});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>o>>r;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>x[j]>>y[j];
		}
		for(int j=1;j<=k[i];j++)
		{
			if(f[x[j]]==0)
			{
				for(int l=x[j];l<=n*m+x[j]+1;l+=m)
					if(l!=x[j]+(i-1)*m)
						add(x[j]+(i-1)*m,l,y[j]);
				f[x[j]]=1;
			}
			for(int l=1;l<=k[i];l++)
				if(l!=j)
					add(x[j]+(i-1)*m,x[l]+(i-1)*m,y[j]);
		}
	}
	for(int i=1;i<=r;i++)
	{
		cin>>st>>ed;
		t[st][++t1[st]]=ed;
	}
	for(int i=1;i<=m;i++)
	{
		if(t1[i]==0)
			continue;
		for(int j=1;j<=m*n;j++)
			dis[j]=0x3f3f3f;
		for(int j=1;j<=m*n;j++)
			vis[j]=0;
		dj(i);
		for(int j=1;j<=t1[i];j++)
			cout<<dis[t[i][j]]+w[i]+w[t[i][j]]<<endl;
	}
	return 0;
}
