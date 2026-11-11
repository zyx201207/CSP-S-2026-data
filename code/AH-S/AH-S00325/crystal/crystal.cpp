#include<bits/stdc++.h>
using namespace std;
/*
 5 5 
 1 2 4 8 9
  
 3
 
  5 8
 -3 -1 2 2 7
 
  4
 */
int n,m;
long long a[500010];
long long sum[500010];
long long dp[500010];
long long maxn;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		sum[i]=a[i+1]-a[i];
	}
	for(int i=1;i<n;i++){
		dp[i]=dp[i-1]+sum[i]*i;
	}
	/*for(int i=1;i<n;i++){
		cout<<dp[i]<<" ";
	}*/
for(int i=1;i<n;i++){
	int l=i,r=n;
	while(l<r){
		long long mid=(l+r)/2;
		long long x=dp[mid-1]-dp[i-1]-(a[mid]-a[i])*(i-1);
		if(x<=m){
			l=mid+1;
			maxn=max(maxn,mid-i+1);
		}else{
			r=mid;
		}
		//cout<<i<<" "<<l<<" "<<r<<endl;
	}
}
cout<<maxn;
	return 0;
}
