#include<bits/stdc++.h> 
using namespace std;
long long n,m,z=1,c[500005],dp[10][500005];
long long a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=(a[i]-a[i-1])+b[i-1];
		c[i]=a[i]-a[i-1];
	}
	dp[1][1]=1;
	dp[2][1]=0;
	long long l2=0;
	for(int i=2;i<=n;i++){
		dp[1][i]=dp[1][i-1];
		long long l=i-dp[1][i]+1;
		l2=l2+dp[2][i-1]+(l-1)*c[i];
		while(l2>m){
			l2=l2-b[i]+b[dp[1][i]];
			l--;
			dp[1][i]++;
		}
		z=max(z,l);
	}
	cout<<z;
	return 0;
}
