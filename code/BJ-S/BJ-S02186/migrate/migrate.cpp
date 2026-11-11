#include<bits/stdc++.h>
#define int long long
#define pi pair<int,int>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=2000005;
inline void ckmax(int& x,int y){x=max(x,y);}
inline void ckmin(int& x,int y){x=min(x,y);}
int n,a[N],c,_,d,dp1[N][2],dp2[N][2],l[N],r[N],s[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&_);
	while(_--){
		scanf("%lld%lld",&n,&d);
		rep(i,1,n) scanf("%lld",&a[i]);
		rep(i,1,n){
			dp1[i][0]=0,dp1[i][1]=0;
			s[i]=0;
			l[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
			r[i]=(i==n?n:lower_bound(a+1,a+n+1,a[i+1]-d)-a-1);
			ckmin(r[i],i-1);
		}
		int ans=0;
		rep(i,1,n){
			if(l[i]<=r[i]){
				dp1[i][0]=dp1[l[i]][0]+1;
				dp1[i][1]=dp1[l[i]][1]+(l[i]<r[i]?dp1[l[i]+1][0]:0);
				if(l[i]==r[i] && r[i]<i-1) ans+=dp1[l[i]+1][0];
			}
		}
		rep(i,1,n) ans+=dp1[i][1];
		rep(i,1,n){
			dp1[i][0]=1,dp1[i][1]=0;
			if(l[i]<=r[i]){
				dp1[i][0]+=s[r[i]]-s[l[i]-1];
				dp1[i][1]+=s[min(i-2,r[i])]-s[l[i]-1];
			}
			s[i]=s[i-1]+dp1[i][0];
			//printf("%lld | l = %lld, r = %lld, dp[0] = %lld, dp[1] = %lld\n",i,l[i],r[i],dp1[i][0],dp1[i][1]);
		}
		rep(i,1,n){
			s[i]=0;
			r[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
			l[i]=(i==1?1:upper_bound(a+1,a+n+1,a[i-1]+d)-a);
			ckmax(l[i],i+1),ckmin(r[i],n);
		}
		s[n+1]=0;
		_rep(i,n,1){
			dp2[i][0]=1,dp2[i][1]=0;
			if(l[i]<=r[i]){
				dp2[i][0]+=s[l[i]]-s[r[i]+1];
				dp2[i][1]+=s[l[i]]-s[max(i+2,r[i])+1];
			}
			s[i]=s[i+1]+dp2[i][0];
			//printf("%lld | l = %lld, r = %lld, dp[0] = %lld, dp[1] = %lld\n",i,l[i],r[i],dp2[i][0],dp2[i][1]);
		}
		rep(i,2,n) ans+=dp1[i][1]*dp2[i-1][1];
		printf("%lld\n",ans/2);
	}
	return 0;
}
