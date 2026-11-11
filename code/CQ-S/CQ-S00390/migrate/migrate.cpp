#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005;
int c,t,n,d,x[N],dp[N],cnt[N],cnt2[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			memset(dp,0,sizeof(dp));
			memset(cnt,0,sizeof(cnt));
			memset(cnt2,0,sizeof(cnt2));
			cnt[i]=cnt2[i]=1;
			for(int j=i+1;j<=n;j++){
				int l=i,r=j,t=0;
				while(l<=r){
					int mid=(l+r)/2;
					if(x[j]-x[mid]<=d){
						t=mid;
						r=mid-1;
					}else l=mid+1;
				}
				l=t;
				r=j-1;
				int t2=0;
				while(l<=r){
					int mid=(l+r)/2;
					if(dp[mid]<=dp[t]){
						t2=mid;
						l=mid+1;
					}else r=mid-1;
				}
				dp[j]=dp[t]+1;
				cnt[j]=cnt2[t2]-cnt2[t-1];
				cnt2[j]=cnt2[j-1]+cnt[j];
				if(cnt[j]==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
