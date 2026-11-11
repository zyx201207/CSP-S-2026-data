#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[2000005],dp[2000005],s[2000005],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(int i = 1;i<=t;i++){
		scanf("%lld%lld",&n,&d);
		for(int j = 1;j<=n;j++){
			scanf("%lld",&x[j]);
		}
		s[1]=1;
		for(int j = 2;j<=n;j++){
			s[j]++;
			if(abs(x[j]-x[j-1])<=d){
				s[j]+=s[j-1];
			}
			if(j>=3&&x[j]-x[j-2]<=d){
				ans+=s[j-2];
			}
			if(j>=4&&x[j]-x[j-2]<=d&&x[j-1]-x[j-3]<=d&&x[j]-x[j-3]>d){
				ans+=s[j-3];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
