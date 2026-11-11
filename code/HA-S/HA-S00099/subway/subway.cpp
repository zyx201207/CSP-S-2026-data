//the end
//wish good luck

#include <bits/stdc++.h>
using namespace std;

auto fr=[]()->void
{
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	return;
};

const int N=1e6+10, M=5e5+10;
vector<vector<pair<int,int>>> a(N);
vector<int> c[N];
int b[M];

int d[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
void dij()
{
	while(!pq.empty())
	{
		int u=pq.top().second; pq.pop();
		
		for(auto V:a[u])
		{
			int v=V.second, w=V.first;
			if(d[u]+w<d[v])
			{
				d[v]=d[u]+w;
				pq.push({d[v],v});
			}
		}
	}
	
	return;
}

signed main()
{
	fr();
	
	int cc,n,m,dd,q; cin>>cc>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	
	int cnt=n;
	for(int i=1;i<=n;i++)
	{
		int k; cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y; cin>>x>>y;
			a[++cnt].push_back({y,i});
			a[i].push_back({y,cnt});
			c[x].push_back(i);
		}
	}
	
	for(int i=1;i<=q;i++)
	{
		int x,y; cin>>x>>y;
		memset(d,0x3f,sizeof d);
		int ans=INT_MAX;
		for(auto u:c[x]){
			pq.push({0,u}); d[u]=0; dij();
			for(auto v:c[y]){
				ans=min(ans,d[v]);
			}
		}
		
		cout<<ans+b[y]+b[x]<<'\n';
	}
	
	for(int i=1;i<=cnt;i++){
		cout<<d[i]<<' ';
	}
	
	return 0;
}
