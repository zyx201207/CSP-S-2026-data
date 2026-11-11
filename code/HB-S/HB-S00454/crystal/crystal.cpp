#include <bits/stdc++.h>
using namespace std;
const int MOD=5e5+5;
long long n,m,a[MOD],dis[MOD];
long long ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1]>>a[2];
	long long hj=a[2]-a[1];
	long long flag=0;
	for(long long i=3;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]+hj){
			flag=1;
		}
	}
	if(flag==0){
		ans=0;
		for(long long i=n;i>=1;i--){
			if(m-(a[n]-a[i])>=0){
				ans++;
				m-=a[n]-a[i];
			}
		}
		cout<<ans;
	}
	else{
		dis[1]=0;
		sort(a+1,a+n+1);
		long long dp=2,kl=n-1;
		while(kl--){
			for(long long i=dp;i<=n;i++){
				dis[i]=dis[i-1]+(i-dp+1)*(a[i]-a[i-1]);
			}
			long long op=0;
			for(long long i=dp;i<=n;i++){
				if(dis[i]<=m){
					op++;
				}
			}
			ans=max(ans,op+1);
			dis[dp]=0;
			dp++;
		}
		cout<<ans;
	}
	return 0;
}
