#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[2000010],dis[2000010],n,d,x[2000010];
bool vis[2000010];
void bfs(ll u){
	memset(cnt,0,sizeof cnt);
	memset(vis,0,sizeof vis);
	memset(dis,0,sizeof dis);
	queue<ll>q;
	cnt[u]=vis[u]=1;
	dis[u]=0;
	q.push(u);
	while(!q.empty()){
		u=q.front();
		q.pop();
		for(ll i=u+1;i<=n;i++){
			if(x[i]-x[u]>d) break;
			if(dis[i]==dis[u]+1) cnt[i]+=cnt[u];
			if(!vis[i]){
				cnt[i]=cnt[u];
				vis[i]=1;
				dis[i]=dis[u]+1;
				q.push(i);
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	scanf("%lld%lld",&c,&t);
	while(t--){
		ll C=0;
		scanf("%lld%lld",&n,&d);
		for(ll i=1;i<=n;i++) scanf("%lld",x+i);
		for(ll i=1;i<=n;i++){
			bfs(i);
			for(ll j=i+1;j<=n;j++){
				if(cnt[j]==2) C++;
			}
		}
		printf("%lld\n",C);
	}
	return 0;
}
