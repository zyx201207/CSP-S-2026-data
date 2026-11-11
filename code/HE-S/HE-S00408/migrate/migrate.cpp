#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n;
ll d,x[2000005];
ll dp[2000005];
ll cnt[2000005],ans;

int main(){
	freopen("migrate.in","r",stdin);	
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(cnt,0,sizeof(cnt));
		scanf("%d%lld",&n,&d);
		ans=0;
		for(int i=1;i<=n;++i){
			scanf("%lld",&x[i]);
		}
		for(int i=2;i<=n;++i){
			ll minn=0x3f3f3f3f3f3f3f3f;
			for(int j=1;j<i;++j){
				if(x[j]+d>=x[i]) 
					minn=min(minn,dp[j]+1);
			}
			for(int j=1;j<i;++j){
				if(minn==dp[j]+1){
					dp[i]=minn;
					cnt[i]++;
				}
			}
		}
		for(int i=1;i<=n;++i){
			if(cnt[i]==2)++ans;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
