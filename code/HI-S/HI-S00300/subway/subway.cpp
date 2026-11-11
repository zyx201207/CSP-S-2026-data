#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node{
	ll v,ist;
};

ll c,n,m,d,q;
ll x,y;
ll res;
ll w[50010],k[510];
ll a[21][500010];
ll t[21][500010];
vector<node> e[500010];

void dfs(ll u,ll timee,ll id,ll cnt,ll fa){
	if(cnt>m) return;
	if(u==y){
		for(int i=1;i<=k[id];i++){
			if(a[id][i]==u){
				timee+=t[id][i];
				break;
			}
		}
		res=min(res,timee+w[u]);
	}
	cnt++;
	for(int i=0;i<e[u].size();i++){
		ll v=e[u][i].v,ist=e[u][i].ist;
		if(u==fa) continue;
		ll ti=timee;
		if(id==0){
			ti+=t[ist][i+1];
		}
		else{
			if(id==ist){
				ti+=t[id][i+1];
			}
			else{
				ti+=t[id][i+1]+t[ist][i];
			}
		}
		dfs(v,ti,ist,cnt,u);
	}
}

int main() {
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%lld%lld",&a[i][j],&t[i][j]); 
			if(j==1) continue;
			e[a[i][j-1]].push_back({a[i][j],i});
			e[a[i][j]].push_back({a[i][j-1],i});
		}
	} 
	while(q--){
		scanf("%lld%lld",&x,&y);
		res=1e18;
		dfs(x,w[x],0,0,0);
		printf("%lld",res);
	}
	
	return 0;
} 
