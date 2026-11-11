#include<bits/stdc++.h>
using namespace std;
long long a[500050];
long long dp[500050];
long long dp2[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dp[1]=0,dp2[1]=1;
	long long x=0,y=0,ss;
	for(int i=2;i<=n;i++){
		for(int j=i-1;j>0;j--){
			ss=dp2[j]*(a[i]-a[j]);
			if(dp[j]+ss>m)break;
			else{
				if(dp2[j]>=dp2[i])dp[i]=dp[j]+ss,dp2[i]=dp2[j]+1;
			}
		}
	}
	long long s=0;
	for(int i=1;i<=n;i++)if(dp2[i]>s)s=dp2[i];
	cout<<s;
	return 0;
} 
