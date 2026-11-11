//GZ-S00212，任柏翰 ，贵阳市南明区李端芬中学 
#include<bits/stdc++.h>
using namespace std;

const int N=505;
const int M=5*1e5+5;
int c,n,m,d,q;
int w[N],t[N][M];
struct node{
	int v;
	int typ;
};
struct qq{
	int u;
	int last_typ;
};
vector<node> adj[N];
long long vis[N][N];

long long bfs(int st,int en)
{
	if(vis[st][en]) return vis[st][en];
	queue<qq> q;
	q.push(qq{st,0});
	while(!q.empty())
	{
		qq go=q.front();
		int u=go.u;
		int l_typ=go.last_typ;
		q.pop();
		for(int i=0;i<adj[u].size();i++)
		{
			node to=adj[u][i];
			int v=to.v;
			int typ=to.typ;
			int res=vis[st][u];
			if(typ!=l_typ)
			{
				res+=t[u][l_typ]+t[u][typ];
			}
			if((res<vis[st][v]) || (!vis[st][v]))
			{
				vis[st][v]=res;
				q.push(qq{v,typ});
			}
		}
	}
	return vis[st][en];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);    
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];	
	} 
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=2*k;j+=2)
		{
			int au,tu,av,tv;
			cin>>au>>tu>>av>>tv;
			adj[au].push_back(node{av,i});
			adj[av].push_back(node{au,i});
			t[j][i]=tu;
			t[j+1][i]=tv;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int s,t;
		cin>>s>>t;
		int ans=w[s]+bfs(s,t)+w[t];
		cout<<ans<<'\n';
	}
	
	return 0;	
} 
