#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 510,M = 5e5+10;

int n,m;
ll w[M],ans,dis[N];
vector<pair<int,ll> > a[2*M];
queue<pair<int,ll> > q;

void bfs(int s)
{
	memset(dis,0x3f,sizeof(dis));
	q.push({s,0});
	dis[s] = w[s];
	while(!q.empty())
	{
		auto cur = q.front();
		q.pop();
		int x = cur.first;
		for(auto i : a[x])
		{
			int y = i.first;
			ll d = i.second;
			if(dis[x]+d <= dis[y])
			{
				dis[y] = dis[x]+d;
				q.push({y,d});
			}
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i = 1; i<= m; i++)
	{
		cin>>w[i];
	}
	for(int i = 1; i<= n; i++)
	{
		int k;
		cin>>k;
		for(int j = 1; j<= k; j++)
		{
			int x;
			ll y;
			cin>>x>>y;
			a[x].push_back({i+m,y});
			a[i+m].push_back({x,y});
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		bfs(x);
		cout<<dis[y]+w[y]<<"\n";
	}
	return 0;
}
