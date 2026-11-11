/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=505;
const ll M=4e5+5;
const ll INF=0x3f3f3f3f3f3f3f3f;

ll c,n,m,d,q;
ll w[M];	

vector<ll> subway[N];	//第i条线路到达的地铁站编号 
vector<ll> vec[M];	//存储每个地铁站有的地铁线路 

bool vis[M];	//判断该地铁站是否已经来过 
ll u[M][N];	//统计第i个站厅到j号线站台的时间 

ll ans=INF;


inline void dfs(ll k,ll sum,ll e_d)	//k,当前地铁站编号   sum,当前总耗时   e_d结束地铁站 
{
	if(k==e_d)
	{
		ans=min(ans,sum);
		return ;
	} 
	
	vis[k]=true; 
	for(auto it:vec[k])
	{
		for(auto next:subway[it])
		{
			if(vis[next]) continue;
			
			dfs(next,sum+u[k][it]+u[next][it],e_d);
		}
	}
	vis[k]=false;
	return ;
}

int main()
{
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++) cin>>w[i];
	
	for(int i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		
		for(int j=1;j<=k;j++)
		{
			ll a,b;
			cin>>a>>b;
			subway[i].push_back(a);
			vec[a].push_back(i);
			u[a][i]=b; 
			
		}
		
	}
	while(q--)
	{
		ll x,y;
		cin>>x>>y;
		
		dfs(x,0,y);
		ans+=w[x]+w[y];
		cout<<ans<<endl;
		
		ans=INF;
	}
	return 0;
} 
