#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,d,ans=0;
int a[N],dp[N];
//int wo(int n){
//	if(n<2){
//		return 0;
//	}
//	for(int i=n;i<=d;i++){
//		dp[n]+=wo(n-i);
//	}
//	return 0;
//}
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		dp[1]=0;
		dp[0]=0;
		dp[2]=0;
		dp[3]=0;
		dp[4]=1;
		for(int i=5;i<=n;i++){
			for(int j=n-1;j>=1;j--){
				if(a[i]-a[j]<=d){
					dp[i]+=dp[j];
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=dp[i];
		}
		cout<<ans;
	}
	return 0;
}

