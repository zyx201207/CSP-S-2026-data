#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#define endl '\n'
using namespace std;
using ll=long long;
const int MAXN=2000005;
int c,n,dis[MAXN],dp[MAXN];
ll d,x[MAXN];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	ll ans=0;
	if(n<=300){
		for(int u=1;u<=n;u++){
			dp[u]=1,dis[u]=0;
			for(int v=u+1;v<=n;v++) dis[v]=1e9,dp[v]=0;
			for(int v=u+1;v<=n;v++){
				for(int j=v-1;j>=u;j--){
					if(x[v]-x[j]>d) break;
					if(dis[j]+1<dis[v])
						dis[v]=dis[j]+1,dp[v]=dp[j];
					else if(dis[j]+1==dis[v])
						dp[v]+=dp[j];
				}
				if(dp[v]==2) ans++;
			}
		}
	}else if(c==11||c==12){
		ll c=x[2]-x[1];
		ll s=d/c;
		for(int u=1;u<=n;u++){
			ll v=2*s+u-1;
			if(v<=n&&v>u+1) ans++;
		}
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	cin>>c>>T;
	while(T--){
		
		solve();
	}
	return 0;
}
