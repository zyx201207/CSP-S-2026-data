// I just wanted to hide,
// Didn't want to face the world, 
// As everything has lost meaning, 
// As I has lost meaning, 
// I just sat there still.

//It may be my last CSP-S.
//Hope we all have a bright future.
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<string>
#include<queue>
using namespace std;
typedef long long ll;
const int N=2e6+5,M=305;
int c,t,n;
ll a[N],dp[M][M],dis[M][M],d;
void solve1(){
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int l=1;l<n;l++){
			dis[l][l]=0;
			for(int i=l+1;i<=n;i++){
				int j=lower_bound(a+l,a+n+1,a[i]-d)-a;
				if(j>=i) dis[l][i]=-1;
				else dis[l][i]=dis[l][j]+1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)
				if(dis[i][j]!=-1) dp[i][j]=1;
		}
//		int ans=0;
//		for(int len=3;len<=n;len++){
//			for(int i=1;i+len-1<=n;i++){
//				int j=i+len-1;
//				for(int k=i+1;k<j;k++){
//					if(dis[i][j]==dis[i][k]+dis[k][j])
//						dp[i][j]+=dp[i][k]*dp[k][j];
//				}
//				if(dp[i][j]==2) ans++;
//			}
//		}
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				dp[i][j]=0;
				for(int k=i+1;k<j;k++){
					if(dis[i][k]+dis[k][j]==dis[i][j]){
						dp[i][j]++;
					}
				}
				if(dp[i][j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(c<=6) solve1();
	return 0;
}

