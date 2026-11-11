#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,c,d,q,a[N],ans,x,y,b[N];
struct nd{
	ll v,s;
};
vector<nd> g[N];

void dfs(ll u,ll w){
	if(u==y){
		ans=min(ans,w);
		return;
	}
	for(ll i=0;i<b[u];++i){
		dfs(g[u][i].v,w+g[u][i].s);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;++i){
		cin>>a[i];
	}
	for(ll i=1;i<=q;++i){
		ll k,u,v,uu;
		cin>>k;
		for(ll j=1;j<=k;++j){
			cin>>u>>v;
			if(j==1){
				uu=u;
			}else{
				b[uu]++;
				g[uu].push_back((nd){u,v});
				uu=u;
			}
		}
	}
	
	for(ll i=1;i<=q;++i){
		cin>>x>>y;
		ans=LLONG_MAX;
		ll o=a[x]+a[y];
		dfs(x,0);
		cout<<o+ans<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


*/
