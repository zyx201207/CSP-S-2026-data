#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
const int N=2e6+10;
int x[N];
int dp[N],cnt[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		int ans=0;
		for(int l=1;l<=n;l++){
			memset(dp,0x3f,sizeof dp);
			memset(cnt,0,sizeof dp);
			dp[l]=0;
			cnt[l]=1;
			for(int i=l;i<=n;i++){
				int pos=lower_bound(x+1,x+1+i,x[i]-d)-x;
				for(int j=max(l,pos);j<=i;j++){
					if(dp[i]>dp[j]+1){
						dp[i]=dp[j]+1;
						cnt[i]=cnt[j];
					}
					else if(dp[i]==dp[j]+1) cnt[i]+=cnt[j];
				}
			}			
			for(int i=l;i<=n;i++){
				if(cnt[i]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
