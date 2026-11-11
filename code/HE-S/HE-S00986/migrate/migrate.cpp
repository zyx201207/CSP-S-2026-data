#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int n,d,a[N],dp[N],ton[N],ans;
int c,t;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++) dp[i]=0x3f3f3f3f;
		dp[1]=0;
		ans=0;
		for(int j=1;j<=N;j++) ton[j]=0;
		for(int i=1;i<=n;i++){
			for(int j=i-d;j<=i;j++){
				if(j>=1){
					dp[i]=min(dp[i],dp[j]+1);
				}
			}
			ton[dp[i]]++;
		}
		for(int i=1;i<=N;i++){
			if(ton[i]==2) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
