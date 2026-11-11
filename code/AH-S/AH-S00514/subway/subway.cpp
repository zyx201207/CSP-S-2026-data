#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,c,d,Q,w[N],dep[N],hour[N][51];
struct Node{
	int id;
	int xianlu;
	int t;
};
struct node{
	int len;
	int point;
	int line;
	bool can;
};
vector<Node> e[N];
priority_queue<vector<node>> q;

void dij()
{
	while(!q.empty())
	{
		int u=q.top().point;
		for(auto ee:e[u])
		{
			int v=ee.id;
			int l=ee.xianlu;
			int time=ee.t;
			if(q.top().line==l || q.top().can)
			{
				if(dep[u]<dep[v])
				{
					q.push({-q.top().len,v,l,0});
					dep[v]=dep[u];
				}
			}
			else
			{
				int timme=time+hour[u][q.top().line];
				if(dep[v]<dep[u]+timme)
				{
					dep[v]=dep[u]+timme;
					q.push({-dep[v],v,l,0});
				}
			}
		}
		q.pop();
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k; cin>>k;
		int aa,tt;
		cin>>aa>>tt;
		hour[aa][i]=tt;
		for(int j=1;j<k;j++)
		{
			int a,t;
			cin>>a>>t;
			e[aa].push_back({a,i,tt});
			e[a].push_back({aa,i,t});
			hour[a][i]=t;
			aa=a;
			tt=t;
		}
	}
	while(Q--)
	{
		int S,T;
		cin>>S>>T;
		memset(dep,0x3f,sizeof dep);
		dep[S]=0;
		q.push({0,S,1,1});
		dij();
		cout<<dep[T]+w[S]+w[T]<<"\n";
	}
	return 0;
}
