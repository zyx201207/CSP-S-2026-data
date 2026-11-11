#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[5005],f[5005],a[5005];
int calc(int n,int d){
	memset(dp,0x3f,sizeof(dp));
	memset(f,0,sizeof(f));
	dp[1]=0;
	for(int i=2;i<=n;i++){
		for(int j=i-1;j;j--){
			if(a[i]-a[j]<=d) dp[i]=min(dp[i],dp[j]+1);
			else break;
		}
	}
	f[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=i-1;j;j--){
			if(a[i]-a[j]<=d&&dp[j]==dp[i]-1) f[i]+=f[j];
			if(f[i]>3) f[i]=3;
		}
	}
	int res=0;
	for(int i=1;i<=n;i++) if(f[i]==2) res++;
	return res;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,ans=0,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		while(n){
			ans+=calc(n,d);
			for(int i=2;i<n;i++) a[i]=a[i+1]-a[1];
			a[1]=a[2]-a[1];
			n--;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
