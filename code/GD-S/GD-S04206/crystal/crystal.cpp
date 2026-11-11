#include<bits/stdc++.h>
using namespace std;
const int MAX=5e5+10;
long long n,m;
long long a[MAX],sum[MAX];
long long dp[MAX];
long long l,r,mid;
long long max1=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		sum[i]=sum[i+1]+a[n]-a[i];
	}
	dp[1]=1;
	for(int i=n;i>=2;i--){
		l=1;
		r=i;
		while(l<r){
			mid=(l+r)/2;
			if(sum[mid]-(sum[i]-sum[n])-(i-mid)*(a[n]-a[i])>m){
				l=mid+1;
			}else{
				r=mid;
			}
		}
		dp[i]=i-l+1;
	}
	for(int i=1;i<=n;i++){
		max1=max(max1,dp[i]);
	}
	cout<<max1;
} 
