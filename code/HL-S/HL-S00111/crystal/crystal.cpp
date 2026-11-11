#include<bits/stdc++.h>
using namespace std;
long long n,m,ji;
const int N = 5e5+10;
long long dp[N],f[N],a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m>>a[1];
	for(long long i=2;i<=n;i++){
		cin>>a[i];
		f[i]=a[i]-a[i-1];
	}
	long long k=0,sum=0;
	for(long long i=1;i<n;i++){
		for(long long j=i;j<=n;j++){
			ji++;
			sum+=f[j]*ji;
			if(sum>m){
				sum=0;
				j-=1;
				dp[k++]=ji;
				ji=0;
			}
		}
	}
	sum=0;
	for(long long i=0;i<k;i++){
		sum=max(sum,dp[i]);
	}
	cout<<sum;
}
