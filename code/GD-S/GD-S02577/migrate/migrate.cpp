#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=2*1e6+10;
ll c,t;
ll x[maxn];
vector<ll> g[maxn];
struct Node{
	ll step;
	ll id;
};
queue<Node> q;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ll ans=0;
		ll n,d;
		scanf("%lld%lld",&n,&d);
		for(ll i=1;i<=n;i++) x[i]=0;
		for(ll i=1;i<=n;i++) g[i].clear();
		for(ll i=1;i<=n;i++) scanf("%lld",&x[i]);
		for(ll i=1;i<=n;i++){
			for(ll j=i-1;j>=1&&abs(x[j]-x[i])<=d;j--){
				g[i].push_back(j);
			}
		}
		for(ll i=1;i<=n;i++){//假设i为起点,j为终点 
			for(ll j=i+1;j<=n;j++){
				//搜索g[j],把能搜到i的路径计数，并且记录最短路径
				ll cnt=0,minnum=0x7f7f7f7f;
				q.push({0,j});
				while(!q.empty()){
					Node t=q.front();
					q.pop();
					if(t.id==i){
						if(minnum>t.step){
							minnum=t.step;
							cnt=1;
						}else if(minnum==t.step){
							cnt++;
						}
						continue;
					}
					for(ll k=0;k<g[t.id].size();k++){
						q.push({t.step+1,g[t.id][k]});
					}
				}
				if(cnt==2) ans++;
			}
		}
		printf("%lld",ans);
		if(t) printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
