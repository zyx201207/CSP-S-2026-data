#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
//#define debug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define int long long
using namespace std;
const int M = 1000;
const int N = 500;
struct node
{
	int v,idx,w;
};
struct qnode
{
	int u,idx,val;
};
struct cmp
{
	bool operator()(const qnode &x,const qnode &y) const
	{
		return x.val>y.val;
	}
};
int c,n,m,d,q;
int w[M+5],k[N+5],a[N+5][M+5],t[N+5][M+5],f[N+5][M+5];
vector<node> g[N+5][M+5];
vector<int> cand[M+5];
bool vis[N+5][M+5];
priority_queue<qnode,vector<qnode>,cmp> pr_q;

void dijkstra(int st)
{
	memset(f,0x3f,sizeof(f));
	memset(vis,false,sizeof(vis));
	for(int pth:cand[st])
	{
		f[pth][st] = t[pth][st];
		pr_q.push({st,pth,t[pth][st]});
	}
	
	while(pr_q.size())
	{
		qnode front = pr_q.top();pr_q.pop();
		
		int u = front.u,idu = front.idx;
		if(vis[idu][u]) continue;
		vis[idu][u] = true;
		
//		debug(u);debug(idu);debug(f[idu][u]);
		
		for(node tmp:g[idu][u])
		{
			int v = tmp.v,w = tmp.w,idv = tmp.idx;
//			debug(v);debug(w);debug(idv);
			if(f[idu][u]+w<f[idv][v])
			{
				f[idv][v] = f[idu][u]+w;
				pr_q.push({v,idv,f[idv][v]});
			}
		}
	}
}

void solve(int st,int en)
{
	if(st==en)
	{
		cout<<"0\n";
		return ;
	}
	
	dijkstra(st);
	
	int ans = 1e18;
	for(int i=1;i<=n;i++) 
	{
//		debug(i);debug(en);debug(f[i][en]);
		ans = min(ans,w[st]+w[en]+f[i][en]+t[i][en]);
	}
	
//	debug(ans);
	cout<<ans<<'\n';
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][a[i][j]];
			cand[a[i][j]].push_back(i);
			if(j!=1)
			{
				g[i][a[i][j]].push_back({a[i][j-1],i,0});
				g[i][a[i][j-1]].push_back({a[i][j],i,0});
			}
		}	
	}
	
	for(int k=1;k<=m;k++)
	{
		int len = cand[k].size();
//		debug(len);
		for(int i=0;i<len;i++)
		{
			for(int j=i+1;j<len;j++)
			{
//				cerr<<"!!!!!^&&^&^&^&^&";
				
				int pthu = cand[k][i],pthv = cand[k][j];
				int w = t[pthu][k]+t[pthv][k];
//				debug(w);
				g[pthu][k].push_back({k,pthv,w});
				g[pthv][k].push_back({k,pthu,w});
				
//				cout<<"check make g "<<pthu<<' '<<pthv<<' '<<k<<'\n';
			}
		}
	}
	
	while(q--)
	{
		int st,en;cin>>st>>en;
		
		solve(st,en);
	}
	return 0;
}
/*
0 2 5 20 3
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
1 4

*/
