#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 5e5+10,N = 505,INF = 0x3f3f3f3f;
struct lx{
	int to;
	ll val;
};		//lu xian,qi zhong bao han 1.di tie kou  2.hua fei shi jian
ll c,n,m,d,q,w[M],k[N];
vector<lx> stn[M],graph[M];  //stn shi lu xian,graph shi di tie kou
struct cmp{
	bool operator()(const lx &a,const lx &b){
		return a.val < b.val;
	}
};
void dij(ll from,ll to){
	priority_queue<lx,vector<lx>,cmp> q;
//	vector<bool> vis(m+1,0);
	vector<ll> minDis(m+1,INF);
	q.push({(int)from,0});
	minDis[from] = 0;
	while(!q.empty()){
		lx u = q.top();
		q.pop();
//		vis[u.to] = 1;
		for(auto k:graph[u.to]){
			for(auto k2:stn[k.to]){
//				if(vis[k2.to])continue;
				ll stsum = k2.val+k.val+minDis[u.to];
				if(stsum < minDis[k2.to]){
					minDis[k2.to] = stsum;
					q.push({k2.to,minDis[k2.to]});
				}
			}
		}
	}
//	for(int i=1;i<=m;i++)cout<<minDis[i]<<" ";
//	cout<<'\n';
	cout<<minDis[to]+w[from]+w[to]<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a;
			ll t;
			cin>>a>>t;
			stn[i].push_back({a,t});
			graph[a].push_back({i,t});
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		dij(x,y);
	}

	return 0;
}
