#include<bits/stdc++.h>
const int N=2*1e5+10;
using namespace std;
long long n,m,a[N],dp[N];
bool b[N];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	dp[0]=1;
	dp[1]=a[1];
//	for(int j=1; j<=m; j++){
//		for(int i=n; i>=1; i--){
//			long long qwq=dp[j-1]&a[i];
//			if(b[i]==0 and dp[j]<qwq){
//				b[i]=1;
//				dp[j]=qwq;
//			}
//		}
//	}
	for(int i=1; i<=m; i++){
		for(int j=i; j<=n; j++){
			long long qwq=dp[i-1]&a[j];
			dp[i]=max(dp[i],qwq); 
		}
	}
	//for(int i=1; i<=m; i++) cout<<dp[i]<<" ";
	cout<<dp[m];
	return 0;
}
