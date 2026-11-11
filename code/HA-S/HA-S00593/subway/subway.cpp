#include<bits/stdc++.h>
using namespace std;
int to,n,m,q,d,k,x,y,w[500005],c,b,vis[500005],ans;
struct node{
	int id,t;
};
vector<node> a[500005];
vector<int> v[500005];
void bfs(int st,int en)
{
	queue<node> qu;
	qu.push({st,1});
	vis[st]=1;
	while(!qu.empty())
	{
		node cur=qu.front();
		for(int i = 0;i<a[cur.id].size();i++)
		{
			if(a[cur.id][i].id==en)
			{
				return;
			}
			if(!vis[a[cur.id][i].id])
			{
				if(a[cur.id][i].t!=cur.t)
				{
					ans++;
				}
				qu.push({a[cur.id][i].id,a[cur.id][i].t});
				vis[a[cur.id][i].id]=1;
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>to>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++)
	{
		cin>>k;
		for(int j = 1;j<=k;j++)
		{
			cin>>x>>y;
			v[i].push_back(x);
		}
		for(int j = 0;j<v[i].size()-1;j++)
		{
			a[v[i][j]].push_back({v[i][j+1],i});
		}
	}
	while(q--)
	{
		cin>>c>>b;
		ans=0;
		bfs(c,b);
		cout<<ans*y;
	}
	return 0;
 } 
 //????ccf
