#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
int c,n,m,d,S,T;
long long ww[M+N];
long long dis[M+N],diss[N][N];
bool vis[M+N];
vector<int> tr[M];
struct Edge
{
	int v;
	long long w;
};
vector<Edge> e[N+M];
struct Ques
{
	int S,T,I;
	long long ans;
}a[100010];
bool cmp(Ques A,Ques B)
{
	return A.S<B.S;
}
bool cmp1(Ques A,Ques B)
{
	return A.I<B.I;
}
struct Node
{
	long long x;
	int id;
	friend bool operator<(Node A,Node B)
	{
		return A.x>B.x;
	};
};
priority_queue<Node> q;
void dij(int ss)
{
	for(int i=1;i<=m+n;i++) dis[i]=1e18,vis[i]=0;
	dis[ss]=0;
	q.push({0,ss});
	while(!q.empty())
	{
		int u=q.top().id;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto p:e[u])
		{
			int v=p.v;
			long long w=p.w;
			if(dis[v]>dis[u]+w) 
			{
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
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
	int Q;
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>ww[i];
	if(c>=9 && c<=11)
	{
		for(int i=1;i<=n;i++)
		{
			int k;
			cin>>k;
			int ii[3],z[3];
			for(int j=1;j<=k;j++) cin>>ii[j]>>z[j];
			if(k==2)
			{
				e[ii[1]].push_back({ii[2],z[1]+z[2]});
				e[ii[1]].push_back({ii[2],z[1]+z[2]});
			}
		}
	}
	else if(c>=12 && c<=19)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			int k;
			cin>>k;
			for(int j=1;j<=k;j++)
			{
				int U,W;
				cin>>U>>W;
				tr[U].push_back(m+i);
				cnt=W;
			}
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=0;j<(int)tr[i].size();j++)
			{
				for(int k=j+1;k<(int)tr[i].size();k++) e[tr[i][j]].push_back({tr[i][k],1}),e[tr[i][k]].push_back({tr[i][j],1});
			}
		}
		for(int i=1;i<=n;i++)
		{
			dij(m+i);
			for(int j=1;j<=n;j++) diss[m+i][m+j]=dis[m+j];
		}
		for(int i=1;i<=Q;i++)
		{
			cin>>a[i].S>>a[i].T;
			for(int j=0;j<(int)tr[a[i].S].size();j++)
			{
				for(int k=0;k<(int)tr[a[i].T].size();k++) a[i].ans=min(a[i].ans,ww[a[i].S]+ww[a[i].T]+ diss[ tr[a[i].S][j] ][tr[a[i].T][k]]*cnt);
			}
			cout<<a[i].ans<<"\n";
		}
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			int k;
			cin>>k;
			for(int j=1;j<=k;j++)
			{
				int U,W;
				cin>>U>>W;
				e[U].push_back({m+i,W});
				e[m+i].push_back({U,W});
			}
		}
	}
	for(int i=1;i<=Q;i++) cin>>a[i].S>>a[i].T,a[i].I=i;
	sort(a+1,a+Q+1,cmp);
	for(int i=1;i<=Q;i++)
	{
		if(a[i].S!=a[i-1].S) dij(a[i].S);
		a[i].ans=ww[a[i].S]+ww[a[i].T]+dis[a[i].T];
	}
	sort(a+1,a+Q+1,cmp1);
	for(int i=1;i<=Q;i++) cout<<a[i].ans<<"\n";
	return 0;
}
