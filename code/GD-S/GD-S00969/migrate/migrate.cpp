#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+5;
int o,t;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>o>>t;
	while(t--){
		int n,d,a[maxn],len[maxn],ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			int dp[maxn];
			int z=i+1;
			while(d>=a[z]-a[i]&&z<=n) dp[z++]=1;
			for(int j=i+2;j<=n;j++){
				int k=j-1;
				while(d>=a[j]-a[k]&&k>=i) dp[j]+=dp[k--];
				if(dp[j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
