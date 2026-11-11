#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,n,m,d,q,w[N],dist[N],s,t;
struct node
{
	int v,w;
	bool operator<(const node &other)const
	{
		return w<other.w;
	}
};
vector<node> edge[N];
void dijkstra()
{
	priority_queue<node> q;
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	q.push({s,0});
	while(!q.empty())
	{
		int now=q.top().v;
		q.pop();
		for(auto i:edge[now])
		{
			if(dist[now]+i.w<dist[i.v])
			{
				dist[i.v]=dist[now]+i.w;
				q.push({i.v,dist[i.v]});
			}
		}
	}
	cout<<dist[t]<<"\n";
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		edge[i].push_back({i+n,w[i]});
		edge[i+n].push_back({i,w[i]});
	}
	for(int i=2;i<=m+1;i++)
	{
		int len;
		cin>>len;
		vector<int> b;
		while(len--)
		{
			int idx,val;
			cin>>idx>>val;
			b.push_back(idx+i*n);
			edge[idx+n].push_back({idx+i*n,val});
			edge[idx+i*n].push_back({idx+n,val});
		}
		for(int i:b)
		{
			for(int j:b)
			{
				if(i!=j)
				{
					edge[i].push_back({j,0});
					edge[j].push_back({i,0}); 
				}
			}
		}
	}
	while(q--)
	{
		cin>>s>>t;
		dijkstra();
	}
    return 0;
}
