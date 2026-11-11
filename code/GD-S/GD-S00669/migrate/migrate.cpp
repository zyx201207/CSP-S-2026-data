#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<ll,ll> 
const int N=5010+10;
ll _,T,n,d,a[N],cnt,L[N],R[N],ans,dp[N][N],sum[N][N],s[N][N];
pii p[N];
void init(){
	for(int i=1;i<=n;i++)L[i]=R[i]=a[i]=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j]=sum[i][j]=s[i][j]=0;
		}
	}
	cnt=ans=0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>_>>T;
	while(T--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		ll tx=1;
		for(int i=1;i<=n;i++){
			while(tx<i&&a[i]-a[tx]>d)tx++;
			L[i]=tx;
		}
		tx=n;
		for(int i=n;i>=1;i--){
			while(tx>i&&a[tx]-a[i]>d)tx--;
			R[i]=tx;
		}
		if(n<=5000){
			for(int l=1;l<=n;l++){
				dp[l][l]=0,sum[l][l]=1,s[l][l]=1;
				tx=l;
				for(int r=l+1;r<=n;r++){
					ll dis=max(L[r],(ll)l);
					if(tx<dis){
						tx=dis;
					}
					dp[l][r]=dp[l][dis]+1;
					while(tx<r&&dp[l][tx]==dp[l][tx+1])tx++; 
					sum[l][r]=s[l][tx]-s[l][dis-1];
					if(!sum[l][r])break;
					if(sum[l][r]==2)ans++;
					s[l][r]=s[l][r-1]+sum[l][r];
				}
			}
			printf("%lld\n",ans);
			init();
		}
		/*
		else{
			ll r=0,tot=0;
			for(int i=1;i<=n;i++){
				if(L[i]==1&&R[i]==n){
					r++;
					tot++;
				}
			}
			if(tot==2){
				printf("%lld ",(n-r)*(r-2))
			}
			else puts("0");
		}*/
	}
	return 0;
}
/*
0 1
4 2
1 2 3 4
*/
