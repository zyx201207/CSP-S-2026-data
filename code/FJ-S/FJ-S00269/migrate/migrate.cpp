#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,x[2000005],l[2000005],r[2000005],now,ans,rm[2000005],lm[2000005],vis[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(ll num = 1;num <= t;num++){
		memset(vis,0,sizeof(vis));
		scanf("%lld%lld",&n,&d);
		for(ll i = 1;i <= n;i++){
			scanf("%lld",&x[i]);
			if(i >= 2)x[i] = x[i] - x[1] + 1;
		}
		x[1] = 1;
		for(ll i = 1;i <= n;i++)if(i >= 2 && x[i] - x[i - 1] > d)vis[i] = 1;
		now = 1;
		for(ll i = 1;i <= n;i++){
			if(vis[i])now = i;
			lm[i] = now;
		}
		now = n;
		for(ll i = n;i;i--){
			if(vis[i + 1])now = i;
			rm[i] = now;
		}
		now = 1,ans = 0;
		for(ll i = 1;i <= n;i++){
			now = max(now,i);
			while(now <= n - 1 && x[now + 1] - x[i] <= d)now++;
			r[i] = now;
		}
		now = n;
		for(ll i = n;i;i--){
			now = min(now,i);
			while(now >= 2 && x[i] - x[now - 1] <= d)now--;
			l[i] = now;
		}
		for(ll i = 1;i <= n;i++){
			if(l[i] + 1 >= i)continue;
			if(i == rm[i] || x[i + 1] == x[i] + 1)ans += (min(l[l[i] + 2] - 1,l[i] - 1) - l[l[i] + 1] + l[l[i]] - lm[i] + 1);
			else ans += (min(l[l[i] + 2] - 1,l[i] - 1) - l[l[i] + 1] + l[l[i]] - lm[i] + 1) * (rm[i] - max(r[l[i] + 1],i) + 3);
			//[l[l[i]+1],l[l[i]+2]-1]
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
