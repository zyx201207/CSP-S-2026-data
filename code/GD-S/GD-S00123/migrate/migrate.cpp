#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lpx 105
ll test,t,n,d,a[lpx],cnt[lpx][lpx],maxn=0,ans=0,noww=1;
bool vis[lpx];
void dfs(ll x,ll dis){
	if(x!=1)cnt[x][dis]++;
	for(ll i=x+1;i<=n;++i){
		if(abs(a[i]-a[x])<=d){
			maxn=max(maxn,dis+1);
			dfs(i,dis+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&test,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		ans=0;
		ll ji=1;
		maxn=0;
		for(ll i=1;i<=n;++i)scanf("%lld",&a[i]);
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		for(ll qi=1;qi<=n;++qi){
			dfs(qi,0);
			for(ll i=qi+2;i<=n;++i){
				for(ll j=2;j<=maxn;++j){
					if(cnt[i][j]&&cnt[i][j]==2)ans++;
					else if(cnt[i][j]&&cnt[i][j]!=2)break;
				}
			}
			memset(cnt,0,sizeof(cnt));
		}
		
		printf("%lld\n",ans);
	}
	return 0;
}
