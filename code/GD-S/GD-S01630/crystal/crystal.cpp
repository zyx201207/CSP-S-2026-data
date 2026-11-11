#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],dp[5010][5010],ans=1,d[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool k=1,sum;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if((a[i]-a[i-1]!=a[i-1]-a[i-2])&&i>2)k=0;
		else sum=a[i]-a[i-1];
		d[i]=a[i]-a[i-1];
	}
	if(k){
		long long t=2;
		while(1){
			if((sum*t*(t-1)/2)<=m)ans=t++;
			else break;
		}
		cout<<ans;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			dp[i][j]=dp[i][j-1]+(j-i)*d[j];
			if(dp[i][j]<=m){
				ans=max(ans,j-i+1);
			}else break;
		}
	}
	cout<<ans;
	return 0;
	
} 
