#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n,m,c,d,q;
int x,y;
int w[N],k[505];
bool used[N];
struct node{
	int v;
	int w;
	bool operator < (const node &o) const 
	{
		return w>o.w;
	}
};
vector<node> G[N];

void dij(int x,int y)
{
	priority_queue<node> q;
	for(int i=1; i<=n+m; i++)
	{
		used[i] = false;
	}
	q.push({x,0});
	while(!q.empty())
	{
		node u = q.top();
		q.pop();
		if(used[u.v] == true) continue;
		if(u.v == y)
		{
			cout<<u.w + w[x] + w[y]<<'\n';
			return  ;
		}
		used[u.v] = true;
		for(node t : G[u.v])
		{
			int v = t.v,w = t.w;
			if(used[v] == true) continue;
			q.push({v,w+u.w});
//			cout<<"´Ó"<<u.v <<"µ½"<<v<<" ÀÛ»ý£º"<<w+u.w<<'\n';
		}
	}
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>w[i];
	for(int i=1; i<=n; i++)
	{
		cin>>k[i];
		for(int j=1; j<=k[i]; j++)
		{
			int v,w;
			cin>>v>>w;
			G[m+i].push_back({v,w});
			G[v].push_back({m+i,w});
		}
	}
	
	while(q--)
	{
		cin>>x>>y;
		dij(x,y);
	}
	
	return 0;
}

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
