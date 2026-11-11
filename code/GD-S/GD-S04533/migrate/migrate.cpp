#include<bits/stdc++.h>
using namespace std;
long long a[500050];
long long dp[500050];
long long dp2[500050];
int main(){
	int c,t;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int ct=1;ct<=t;ct++){
	long long n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	dp[1]=0,dp2[1]=0;
	long long x=0,y=0,ss;
	for(int i=2;i<=n;i++){
		if(a[i]>d)for(int j=1;j<i;j++){
			
		}
	}
	long long s=0;
	for(int i=1;i<=n;i++)if(dp2[i]>s)s=dp2[i];
	cout<<s<<endl;}
	return 0;
} 
