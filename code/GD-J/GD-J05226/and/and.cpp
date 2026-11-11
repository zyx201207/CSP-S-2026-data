#include<iostream>
#include<algorithm>
using namespace std;
const int N=2*1e5+10;
int n,m,a[N],dp[N];
//dp[j]表示恰好选j个时二进制按位与的值最大(一维DP) 
bool cmp(int x,int y){
	return x>=y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	dp[1]=a[1];
	for(int i=1;i<=n;i++){
		int x=m-i;
		if(x<0){
			x=0;
		}
		for(int j=m-x;j>=1;j--){
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m]<<'\n';
	return 0;
}
