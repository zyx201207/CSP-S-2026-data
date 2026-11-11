#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int x,y;
};
int l,n,m,o,q,a[500005],b[505][25],c[505][25],d[25],x,y;
vector<int>e[10005];
queue<node>p;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>l>>n>>m>>o>>q;
	for(int i=1;i<=m;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
		for(int j=1;j<=d[i];j++)
		{
			cin>>b[i][j]>>c[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<d[i];j++)
		{
			e[b[i][j]].push_back(b[i][j+1]);
		}
	}
	while(q--)
	{
		cin>>x>>y;
		p.push({x,0});
		while(!p.empty())
		{
			int u=p.front().x,v=p.front().y;
			if(u==y)
			{
				cout<<v<<'\n';
				break;
			}
			for(int i=0;i<e[u].size();i++)
			{
				p.push({e[u][i],v+a[e[u][i]]+c[e[u][i]][i]});
			}
		}
		while(!p.empty())p.pop();
	}
	return 0;
}
