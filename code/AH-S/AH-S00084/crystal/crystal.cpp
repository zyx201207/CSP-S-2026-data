#include<bits/stdc++.h>
using namespace std;
long long a[500005],c[500005],sum[500005],maxn=1,l;
long long dp[5005][5005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,flag=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		c[i]=a[i+1]-a[i];
		l=c[i];
	}
	for(int i=2;i<n;i++){
		if(c[i]!=c[i-1]) flag=1;
	}
	if(flag==1){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dp[i][j]=a[j]-a[i];
			}
		}
		long long j=1;
		for(long long i=2;i<=n;i++){
			long long sum=0;
			for(long long k=j;k<=i;k++) sum+=dp[k][i];
			
			if(sum>m){
				j++;
				for(long long k=j;k<=i;k++) sum-=dp[k][i];
			}
			maxn=max(maxn,i-j+1);
		}
		cout<<maxn;
	}else{
		for(int i=1;i<=n;i++){
			m-=i*l;
			if(m<=n){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
	}
	return 0;
}
