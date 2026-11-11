#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N],b[N];
int dp[N];
int leng(int x){
	int res=0;
	while(x){
		x>>=1;
		res++;
	}
	return res-1;
}
bool check1(){
	for(int i=1;i<=n;i++){
		int x=leng(a[i]);
		if(1<<x!=a[i]+1) return false;
	}
	return true;
}
bool check2(){
	if(n!=1<<leng(n)) return false;
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1) return false;
	}
	return true;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxn=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	int x=a[1];
	for(int i=2;i<=m;i++){
		x&=a[i];
	}
	dp[m]=x;
	if(m==n){
		cout<<x<<"\n";
		return 0;
	}
//	for(int i=m+1;i<=n;i++){
//		dp[i]=dp[i-1];
//		for(int j=1;j<=m;j++){
//			dp[i]=max(dp[i],dp[i-1]^(~a[j])&a[i]);
//		}
//	}
//	cout<<dp[n];
	if(check1()){
		cout<<maxn<<endl;
		return 0;
	}
	if(check2()){
		int ans=a[n];
		for(int i=1;i<=m-1;i++){
			ans&=a[n-i];
		}
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		b[i]=i;
	}
	int ans=0;
	do{
		int cur=a[b[1]];
		for(int i=2;i<=m;i++){
			cur&=a[b[i]];
		}
		ans=max(ans,cur);
	}while(next_permutation(a+1,a+1+n));
	cout<<ans<<endl;
	return 0;
} 
