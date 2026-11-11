#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dp[2000010][5];
int ds[2000010],dpp[2000010];
ll a[2000010];
int c,t,n;
ll d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		if(n<=500){
			int ans=0;
			for(int i=1;i<=n;i++){
				ds[i]=0;
				dpp[i]=1;
				for(int j=i+1;j<=n;j++){
					ds[j]=1e9;
					dpp[j]=0;
					for(int k=j-1;k>=i&&a[j]-a[k]<=d;k--){
						if(ds[k]+1<ds[j]){
							ds[j]=ds[k]+1;
							dpp[j]=dpp[k]; 
						}
						else if(ds[k]+1==ds[j]) dpp[j]=min(3,dpp[j]+dpp[k]);
					}
					ans+=(dpp[j]==2);
				}
			}
			printf("%d\n",ans);
		}
		else{
			ll ans=0,pt=1;
			for(int i=1;i<=n;i++) dp[i][0]=dp[i][1]=dp[i][2]=dp[i][3]=0;
			a[0]=-4e18;
			a[n+1]=4e18;
			for(int i=1;i<n;i++){
				dp[i][0]++;
				while(pt<n&&a[pt+1]<=a[i]+d) pt++;
				if(pt==i) continue;
				else if(pt==i+1){
					if(a[pt]-d>a[i-1]){
						dp[pt][0]+=dp[i][0]+dp[i][1]+dp[i][2];
						dp[pt][3]+=dp[i][3];
						ans+=dp[i][3];
					}
					else if(a[pt]-d>a[i-2]){
						dp[pt][0]+=dp[i][0];
						dp[pt][3]+=dp[i][1];
						ans+=dp[i][1];
					}
					else{
						dp[pt][0]+=dp[i][0];
					}
				}
				else{
					auto trans=[&](int x,int y,int v){
						int g=0,f=0;
						if(a[pt]-d>a[i-1]) f=y;
						else if(a[pt]-d>a[i-2]) f=x+y;
						else f=3;
						if(a[pt-1]-d>a[i-1]) g=y;
						else if(a[pt-1]-d>a[i-2]) g=x+y;
						else g=3;
						if(f==1){
							if(g==0) dp[pt][0]+=v;
							else if(g==1) dp[pt][1]+=v;
							else if(g==2){
								dp[pt][2]+=v;
								int res=0;
								if(x==1) res=upper_bound(a,a+2,a[i-2]+d)-a;
								else res=upper_bound(a,a+2,a[i-1]+d)-a;
								res=max(res,i+1);
								res=min(res,pt);
								ans+=v*(pt-res);
							}
						}
						else if(f!=3){
							assert(g>=2);
							dp[pt][3]+=v;
							if(g==2){
								int res=0;
								if(x==1) res=upper_bound(a,a+2,a[i-2]+d)-a;
								else res=upper_bound(a,a+2,a[i-1]+d)-a;
								res=max(res,i+1);
								res=min(res,pt+1);
								ans+=v*(pt+1-res);
							}
							else ans+=v;
						}
					};
					dp[pt][1]+=dp[i][0];
					trans(1,1,dp[i][1]);
					trans(2,1,dp[i][2]);
					trans(2,2,dp[i][3]);
				}
			}
			printf("%lld\n",ans); 
		}
	}
	return 0;
}
/*
0 100
6 2
-4 -3 -2 -1 3 6


16:04 start
16:26 debug
16:40 wc
17:05 fake
17:07 restart
17:37 wc
*/
