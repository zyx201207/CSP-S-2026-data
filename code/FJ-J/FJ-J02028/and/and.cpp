#include <bits/stdc++.h> 
using namespace std;
int n,m;
long long a[1000001];
long long dp[1000001];
int k[1000001];

//return a > b;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
cin >> n >> m;
for(int i = 1;i <=n;i++){
	cin >> a[i];
}
//sort(a+1,a+1+n,cmp);
dp[1]=a[1];
k[1]=1;
if(m==1){
	cout << a[1];
	return 0;
}
for(int i = 2;i <= n;i++){
	dp[i]=max(dp[i - 1]&a[i],dp[i]);
	if(dp[i] == dp[i-1]&a[i]){
		k[i]=k[i-1]+1;
	}else{
		k[i]=1;
	}
}
for(int i = 1;i<n;i++){
	cout << k[i];
}
int maxn =-1;
for(int i = 1;i<n;i++){
	if(k[i] == m){
	//	maxn=max(maxn,dp[i]);
}
	cout << maxn;
	return 0;
}
}
