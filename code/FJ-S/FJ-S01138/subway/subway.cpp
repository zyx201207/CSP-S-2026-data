#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
#define pll pair<ll,ll>
const ll N=505;
const ll M=5e5+5;
const ll INF=1e18;
ll Inf(ll x){return (!x)?INF:x;}
vector<pll >g[M];
ll n,m,d,p;
ll w[M],f[N][N];
void add(ll u,ll av,ll vw){
	ll au,aw;
	for(auto a:g[u]){
		au=a.fi;aw=a.se+vw;
		if(!f[au][av]||f[au][av]>aw)
			f[au][av]=f[av][au]=aw;
	}
	g[u].push_back({av,vw});
}
void init(){
	for(ll k=1;k<=n;k++)
		for(ll i=1;i<n;i++)
			for(ll l=i+1;l<=n;l++){
				if(i==k||l==k)continue;
				if(f[i][k]&&f[k][l]&&(!f[i][l]||f[i][l]>f[i][k]+f[k][l]))
					f[l][i]=f[i][l]=f[i][k]+f[k][l];
			}
}
ll getans(ll x1,ll y1){
	ll ans=INF;
	ll u,v,s;
	for(auto a1:g[x1]){
		u=a1.fi;
		for(auto a2:g[y1]){
			v=a2.fi;s=a1.se+a2.se;
			ans=min(ans,((u==v)?0:Inf(f[u][v]))+s);
		}
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>n>>m>>d>>p;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1,k,u,aw;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>u>>aw;
			add(u,i,aw);
		}
	}
	init();
	ll x,y;
	while(p--){
		cin>>x>>y;
		cout<<getans(x,y)+w[x]+w[y]<<'\n';
	}
	return 0;
} 
