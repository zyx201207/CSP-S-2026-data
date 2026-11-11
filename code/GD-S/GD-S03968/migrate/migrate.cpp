#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5010;
int c,t,n,d,ans;
int far[N][N],near[N][N]; 
int a[N],dp[N],sum[N];
signed main(){

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
			for(int i=1;i<=n;i++){
				for(int j=i+1,l=i;j<=n;j++){
					while(a[j]-a[l]>d) l++;
					far[i][j]=l;
				}
				for(int j=i+1,l=i;j<=n;j++){
					near[i][j]=l;
					if(a[j+1]-a[l]>d) l=j;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++) dp[j]=0,sum[j]=0;
				dp[i]=1,sum[i]=1;
				for(int j=i+1;j<=n;j++){
					dp[j]=sum[near[i][j]]-sum[far[i][j]-1];
					sum[j]=sum[j-1]+dp[j];
					if(dp[j]==2) ans++;
				}
			}	
			cout<<ans<<endl;
	}

	return 0;
}
//0 3
//9 2
//1 2 3 4 5 6 7 8 9
//9 3
//1 2 3 4 5 6 7 8 9
//7 4
//1 3 5 7 9 11 13
//Oct31==Dec25?
