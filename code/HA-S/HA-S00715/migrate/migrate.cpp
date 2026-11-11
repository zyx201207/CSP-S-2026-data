#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,d,a[2000001],c,t,dp[1001][1001],f[1001][1001],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	const long long maxz=1LL*3*1000000000*1000000000;
	while(t--){
		for(int i=0;i<=1000;i++){
			for(int r=0;r<=1000;r++)dp[i][r]=maxz,f[i][r]=0;
		}
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<n;i++){
			for(int r=i+1;r<=n;r++){if(a[r]-a[i]<=d){f[i][r]=1;dp[i][r]=1;}else break;}
		}
if(c==11 or c==12){
	long long ty=d/(a[2]-a[1]);
		if(d>=2*(a[2]-a[1])){
			for(int i=3;i<=n;i++){ans+=i-i/ty-ty+1;}
		}
		else cout<<0;
}
else{	long long diss;
			for(int i=1;i<n;i++){
				for(int r=i+2;r<=n;r++){
					for(int k=i+1;k<r;k++){
						diss=dp[i][k]+dp[k][r];
						if(diss==dp[i][r])f[i][r]+=f[i][k]+f[k][r];
						else if(diss<dp[i][r])f[i][r]=f[i][k]+f[k][r];
				}
			}
		}
		for(int i=1;i<=n-2;i++)
			for(int r=i+2;r<=n;r++)if(f[i][r]>=2)ans++;
		cout<<ans<<"\n";
}
	}
	return 0;
}
