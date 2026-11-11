#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
using ll=long long; 
struct node{
	ll v,w;
};
struct xys{
	ll t,v;
	bool operator<(const xys &x)const{
		return x.v<v;	
	}
};
vector<node>e[3000005];
map<int,int>mp;
ll w[N];
ll dis[N][N],vis[N][N];
void dij(int s){
	priority_queue<xys>q;
	dis[mp[s]][mp[s]]=0;
	q.push({s,0});
	while (!q.empty()){
		auto qwq=q.top();q.pop();
		ll u=qwq.t;
		if (vis[mp[s]][mp[u]])continue;
		for (auto awa:e[u]){
			ll v=awa.v,w=awa.w;
			if (dis[mp[s]][mp[u]]+w<dis[mp[s]][mp[v]]){
				dis[mp[s]][mp[v]]=dis[mp[s]][mp[u]]+w;
				q.push((xys){v,dis[mp[s]][mp[v]]});		
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x6f,sizeof dis);
	ll c,n,m,d,q;cin>>c>>m>>n>>d>>q;
	for (int i=1;i<=n;++i)cin>>w[i];
	vector<ll>v;
	for (int i=1;i<=m;++i){
		int k;cin>>k;
		for (int j=1;j<=k;++j){
			int x,t;cin>>x>>t;
			v.push_back(x);
			v.push_back(i+x*n);
			v.push_back(n*(n+1)+i);
			e[x].push_back((node){i+x*n,t});
			e[x*n+i].push_back((node){x,t});
			e[n*(n+1)+i].push_back((node){i+x*n,0});
			e[i+x*n].push_back((node){n*(n+1)+i,0});
		}
	}
	sort(v.begin(),v.end());
	for (int i=0;i<v.size();++i)mp[v[i]]=i;
	for (int i=1;i<=n;++i)dij(i);
	for (int i=1;i<=q;++i){
		int s,t;cin>>s>>t;
		cout<<dis[mp[s]][mp[t]]+w[s]+w[t]<<'\n';
	}
	return 0;
}

//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2


