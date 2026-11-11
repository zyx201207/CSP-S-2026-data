#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
ll c,n,m,d,p,w[150005],k[505];
priority_queue<pa,vector<pa>,greater<pa>>q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&p);
	for(ll i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	vector<vector<pair<ll,ll>>>lin(m+n+5);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		ll a,t;
		for(ll j=1;j<=k[i];j++){
			scanf("%lld%lld",&a,&t);
			lin[a].push_back({m+i,t});
			lin[m+i].push_back({a,t});
		}
	}
	while(p--){
		ll x,y,di[150005];
		scanf("%lld%lld",&x,&y);
		bool vis[300005];
		for(ll i=1;i<=n+m;i++){
			di[i]=1e16;
			vis[i]=false;
		}
		q.push({0,x});
		di[x]=0;
		while(!q.empty()){
			pa z=q.top();
			q.pop();
			ll now=z.first,u=z.second;
			if(vis[u])continue;
			vis[u]=true;
			for(auto z:lin[u]){
				ll v=z.first,ww=z.second;
				di[v]=min(di[v],ww+now);
				q.push({di[v],v});
			}
		}
		printf("%lld\n",di[y]+w[x]+w[y]);
	}
	return 0;
}