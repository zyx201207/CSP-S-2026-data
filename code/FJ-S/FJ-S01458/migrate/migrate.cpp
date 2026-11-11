#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2222222;
LL c,t,n,d,point[N],dp[N],ans,x[N],ss,dp2[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		LL j=1; 
		ans=0;
		for(int i=1;i<=n;i++){
			while(x[i]+d>=x[j+1]&&j+1<=n)j++;
			point[i]=j;
		} 	
		for(LL i=n;i>=1;i--){
			ans+=dp[point[i]];
			dp[i]=dp[point[i]];
			if(point[i-1]!=i)dp[i]+=point[i-1]-i;
		}
//		for(LL i=n;i>=1;i--){
//			dp2[i]=dp2[point[i]];
//			if(point[max(ss,i-2)]>i)dp2[i]+=point[i-1]-point[i-2];
//			ans-=dp2[point[i]];
//		}
		cout<<ans<<endl;
	}
	return 0;
}
