#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e6+10;

ll dp[maxn];
ll dpn[maxn];
ll a[maxn];
int n;
ll d;
ll ans=0;

void work(){
	cin>>n>>d;
	ans = 0;
	for(int i=1;i<=n;++i) cin>>a[i];
	
	for(int k=1;k<=n;++k){
		for(int i=k;i<=n;++i){
			dp[i] = 1e18;
			dpn[i] = 0;
		}
		dp[k] = 0;
		dpn[k] = 1;
		for(int i=k;i<=n;++i){
			for(int j=i;j<=n;++j){
				if(d>=a[j]-a[i]){
					if(dp[j]>dp[i]+1){
						dp[j] = dp[i]+1;
						dpn[j] = dpn[i];
					}
					else if(dp[j]==dp[i]+1){
						dpn[j]+=dpn[i];
					}
				}
				else break;
			}
		}
		
		for(int i=k;i<=n;++i){
			if(dpn[i]==2) ans++;
		}
	}
	cout<<ans<<"\n";
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,T;cin>>c>>T;
	while(T--){
		work();
	}

	return 0;
}

