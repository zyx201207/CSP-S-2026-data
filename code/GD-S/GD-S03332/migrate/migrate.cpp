#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=2e17;
int C,T;
int n,d;
ll a[2000006];
ll dis[2000006],cnt[2000006];
void dfs(int x,int c){
	for(int i=x+1;i<=n;i++){
		if(a[x]+d<a[i])
			break;
		if(c+1==dis[i])
			cnt[i]++;
		else if(c+1<dis[i]){
			dis[i]=c+1;
			cnt[i]=1;
		}
		dfs(i,c+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&C,&T);
	while(T--){
		scanf("%d %d",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)dis[j]=INF;
			memset(cnt,0,sizeof cnt);
			cnt[i]=1;
			dis[i]=0;
			dfs(i,0);
			for(int j=1;j<=n;j++)
				if(cnt[j]==2)ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
