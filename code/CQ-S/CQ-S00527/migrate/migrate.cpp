#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=2000005;
int c,t,n,L[MAXN],R[MAXN];
ll x[MAXN],d,ans;
int dp[MAXN][2];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		ans=0;
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		if(n==1){
			printf("0\n");
			continue;
		}
		L[1]=1;R[n]=n;
		for(int i=2;i<=n;i++){
			L[i]=L[i-1];
			while(x[i]-x[L[i]]>d)L[i]++;
		}
		for(int i=n-1;i>=1;i--){
			R[i]=R[i+1];
			while(x[R[i]]-x[i]>d)R[i]--;
		}
		bool Flag=true;
		for(int i=2;i<n;i++){
			if(x[i]-x[i-1]!=x[i+1]-x[i])Flag=false;
		}
		if(Flag){
			ll c=d/(x[2]-x[1]);
			if(c==0||c==1){
				printf("0\n");
				continue;
			}ll ans=0;
			for(int i=1;i<=n;i++){
				if(i+2*c-1<=n)ans++;
			}printf("%lld\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++)dp[i][0]=dp[i][1]=0;
		for(int i=n-1;i>=1;i--){
			int RS=R[i],RSS=R[RS];
			if(RSS==RS||RS==i)continue;
			int d=RS-L[RSS];
			if(d==0){
				dp[i][0]=dp[RS][0];
				dp[i][1]=dp[RS][1];
				int el=RS+1,er=RSS;
				while(el<er){
					int eMid=(el+er)>>1;
					if(L[eMid]==RS)er=eMid;
					else el=eMid+1;
				}int c0=(el+er)>>1;dp[i][0]=dp[i][0]+(RSS-c0+1);
				if(c0==RS+1)continue;
				if(L[c0-1]<RS-1)continue;
				el=RS+1,er=c0-1;
				if(el>er)continue;
				while(el<er){
					int eMid=(el+er)>>1;
					if(L[eMid]==RS-1)er=eMid;
					else el=eMid+1;
				}int c1=(el+er)>>1;dp[i][1]=dp[i][1]+(c0-1-c1+1);
			}
			else if(d==1){
				dp[i][1]=dp[RS][0];
				int el=RS+1,er=RSS;
				while(el<er){
					int eMid=(el+er)>>1;
					if(L[eMid]==RS-1)er=eMid;
					else el=eMid+1;
				}int c1=(el+er)>>1;dp[i][1]=dp[i][1]+(RSS-c1+1);
			}
			else{
				continue;
			}
		}
		for(int i=1;i<=n;i++)ans=ans+dp[i][1];
		printf("%lld\n",ans);
	}
	return 0;
}
