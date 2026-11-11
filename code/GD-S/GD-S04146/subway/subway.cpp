#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,Q,w[500005];
struct N
{
	int x;
	long long t;
	bool operator <(const N &a)const{
		return t>a.t;
	}
};
long long b[500005];
vector<N>a[505],g[500005];
priority_queue<N>q;
void bfs(int s,int t)
{
	for(int i=1;i<=m;i++) b[i]=1e18;;
	b[s]=0;
	while(!q.empty()) q.pop();
	q.push({s,0});
	while(!q.empty())
	{
		N x=q.top();q.pop();
		for(auto y:g[x.x])
		{
			for(auto z:a[y.x])
			{
				if(b[z.x]>x.t+y.t+z.t)
				{
					b[z.x]=x.t+y.t+z.t;
//					cout<<z.x<<" "<<x.x<<" "<<x.t<<" "<<y.t<<" "<<z.t<<" "<<b[z.x]<<'\n';
					q.push({z.x,b[z.x]});
					if(z.x==t) return;
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k,x,y;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>x>>y;
			a[i].push_back({x,y});g[x].push_back({i,y});
		}
	}
	while(Q--)
	{
		int x,y;
		cin>>x>>y;
		bfs(x,y);
		cout<<w[x]+w[y]+b[y]<<'\n';
	}
	return 0;
}
