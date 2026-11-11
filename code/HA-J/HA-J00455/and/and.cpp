#include<iostream>
using namespace std;
const long long N=10000;
long long a[N],dp[N][N][2];
long long max(long long a,long long b){
	if(a>b) return a;
	else return b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long maxn=a[1];
	for(long long i=1;i<=n;i++){
		dp[i][1][1]=a[i];
		dp[i][1][0]=maxn;
		maxn=max(maxn,a[i]);
	}
	for(long long i=2;i<=n;i++){
		for(long long j=2;j<=min(i,m);j++){
			//cout<<"dp["<<i<<"]["<<j<<"][1]=Max(";
			long long max1=dp[j-1][j-1][1]&a[j],max2=dp[j][i][0];
			for(long long k=j-1;k<i;k++){
				if(k>=j){
					max2=max(max2,dp[k][j][0]);
				}
				max1=max(max1,dp[k][j-1][1]&a[i]);
				//cout<<"dp["<<k<<"]["<<j-1<<"][1]&a["<<j<<"]="<<(dp[k][j-1][1]&a[j])<<",";
			}
			//cout<<")="<<max1<<endl;
			dp[i][j][0]=max2;
			dp[i][j][1]=max1;
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<"dp("<<i<<","<<j<<"):"<<dp[i][j][0]<<"  ,  "<<dp[i][j][1]<<endl;
		}
	}*/
	cout<<max(dp[n][m][0],dp[n][m][1]);
	return 0;
}