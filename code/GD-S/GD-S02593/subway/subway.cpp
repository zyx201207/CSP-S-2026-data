#include<iostream>
#include<vector>
#include<map>
using namespace std;

typedef long long ll;
const ll N = 501;
const ll M = 5e5 + 9;
const ll K = 5e5 + 9;
const ll INF = 1e18;

ll c,n,m,d,q;
ll w[M];
ll k[N];

struct edge{
	ll xianlu,cnt;//那条线路第几站 
};
struct node{
	ll cost,stop;//花费以及站点名字 
};

ll tp1,tp2;
ll x,y;

map<pair<ll,ll>,node> a,t;
vector<edge> head[M];//每一个站点被那些路线经过 
bool line_vis[N];//深搜防重复走
bool stop_vis[N];

ll ans;

void dfs(ll now,ll end,ll cost)
{
	if(now == end)
	{
		ans = min(ans,cost);
		return ;
	}
	
	for(edge ttt : head[now])//遍历每一个经过now的线路 
	{
		ll line = ttt.xianlu;
		if(line_vis[line]) continue;
		
		line_vis[line] = true;
		for(ll j = 1; j <= k[line]; j++)
		{
			pair<ll,ll> sub = {line,j};
			if(a[sub].stop == now) continue;
			if(stop_vis[a[sub].stop]) continue;
			
			stop_vis[a[sub].stop] = true;
			
			pair<ll,ll> subt = {line,ttt.cnt};
			node xz = a[subt];
			dfs(a[sub].stop,end,cost + xz.cost + a[sub].cost);
			stop_vis[a[sub].stop] = false;
		}
		line_vis[line] = false;
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(ll i = 1; i <= m; i++) cin >> w[i];
	for(ll i = 1; i <= n; i++)
	{
		cin >> k[i];
		for(ll j = 1; j <= k[i]; j++)
		{
			cin >> tp1 >> tp2;
			a[{i,j}] = {tp2,tp1};
			head[tp1].push_back({i,j});
		}
	}
	
	for(ll i = 1; i <= q; i++)
	{
		cin >> x >> y;
		
		ans = INF;
		dfs(x,y,w[x] + w[y]);
		cout << ans << endl;
	}
	
	return 0;
}

