#include<bits/stdc++.h>

using namespace std;
struct Edge{
	long long w;
	int to;
};
struct node{
	long long w;
	int to;
	bool operator<(const node& others)const{
		return w>others.w;
	}
};
const int N=5e5+1505;
int c,n,m,d,q1,a,cnt;
long long w[N],t;
vector<Edge> vt[N];
priority_queue<node> q;
long long dis[N];
int vis[N];
void dij()
{
	int bg,ed;
	cin>>bg>>ed;
	cnt++;
	memset(dis,0x3f,sizeof dis);
	dis[bg]=0;
	q.push((node){0,bg});
	while(!q.empty())
	{
		node p=q.top();
		q.pop();
		if(vis[p.to]==cnt) continue;
		vis[p.to]=cnt;
		for(int j=0;j<vt[p.to].size();j++)
		{
			int v=vt[p.to][j].to;
			if(dis[v]>dis[p.to]+vt[p.to][j].w){
				dis[v]=dis[p.to]+vt[p.to][j].w;
				q.push((node){dis[v],v});
			}
		}
	}
	cout<<dis[ed]<<'\n';
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q1;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		vt[i].push_back((Edge){w[i],n+i});
		vt[n+i].push_back((Edge){w[i],i});
	}
	for(int i=1;i<=m;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			vt[a+n].push_back((Edge){t,n*2+i});
			vt[n*2+i].push_back((Edge){t,a+n});
		}
	}
	while(q1--)
	{
		dij();
	}
	return 0;
}
