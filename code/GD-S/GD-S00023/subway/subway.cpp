#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=505;
const int M=6e5+5; 
int c,n,m,d,Q,w[M];
vector<pii> a[M],b[N];
int dis[N][N],pre[N];
bool vis[N];
struct node{
	int bi,ch;
	bool operator<(const node &q)const{
		return q.ch<ch;
	}
};
void dij(int s)	{
	for(int i=1;i<=n;i++)	vis[i]=0,pre[i]=0x3f3f3f3f3f3f3f3f;
	pre[s] =0;
	priority_queue<node> q;
	q.push({s,0});
	while(!q.empty())	{
		int x=q.top().bi;
		q.pop();
		if(vis[x])	continue;
		vis[x]=1;
		for(int i=0;i<(int)b[x].size();i++)	{
			int y=b[x][i].first,w=b[x][i].second;
			if(pre[y]>pre[x]+w)	{
				pre[y]=pre[x]+w;
				q.push({y,pre[y]});
			} 
		} 
	}
}
signed main()	{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++)	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)	{
			int x,y;
			cin>>x>>y;
			a[i+m].push_back({x,y});
			a[x].push_back({i+m,y});
		}
	}
	for(int i=1;i<=n;i++)	{
		for(int j=1;j<=n;j++)	{
			if(i!=j)	dis[i][j] =0x3f3f3f3f3f3f3f3f;
			else dis[i][j] =0;
		}
	}
	for(int i=1;i<=m;i++)	{
		for(int j=0;j<(int)a[i].size();++j)	{
			for(int k=j+1;k<(int)a[i].size();k++)	{
				int s1=a[i][j].first-m,s2=a[i][k].first-m;
				dis[s1][s2] = dis[s2][s1] = min({dis[s1][s2],dis[s2][s1],a[i][j].second+a[i][k].second});
			}
		}
	}

	for(int i=1;i<=n;i++)	{
		for(int j=1;j<=n;j++)	{
			if(dis[i][j] != 0x3f3f3f3f3f3f3f3f)	b[i].push_back({j,dis[i][j]});
		}
	}
	for(int i=1;i<=n;i++)	{
		dij(i);
		for(int j=1;j<=n;j++)	dis[i][j] =min(dis[i][j],pre[j]);
	}
	while(Q--)	{
		int x,y;
		cin>>x>>y;
		int ans=LLONG_MAX;
		for(int i=0;i<(int)a[x].size();i++)	{
			for(int j=0;j<(int)a[y].size();++j)	{
				ans=min(ans,w[x]+w[y]+dis[a[x][i].first-m][a[y][j].first-m]+a[x][i].second+a[y][j].second);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
