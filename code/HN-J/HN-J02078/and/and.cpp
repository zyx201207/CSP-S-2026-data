#include<bits/stdc++.h>
using namespace std;
const int N=2.5e5;
int n,m,a[N],mx;
//int dp[N][2],b[N],s[N];
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	/*memset(dp,-1e9,sizeof(dp));
	dp[0][0]=dp[0][1]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]&a[i];
	}for(int i=1;i<=n;i++){
		if(dp[b[s[i]]][1]!=m&&dp[b[s[i]]][0]!=-1e9){
			dp[i][0]=max(dp[b[s[i]]][0]&a[i],dp[i-1][0]);
			dp[i][1]=dp[b[s[i]]][1]+1;
		}else dp[i][0]= dp[i-1][0];
		b[dp[i][1]]=i;
	}*/
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int sum=i;
		for(int l=1;l<m;l++){
			for(int j=i+1;j<=n;j++){
				sum&=a[j];
			}
		}mx=max(mx,sum);
	}
	cout<<mx;
	return 0;
}
