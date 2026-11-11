//胡景涵 GZ-S00175 贵阳市第三中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
long long a[N],dp[N],sum[N];

long long getcost(int i,int j){
	return dp[i]-(a[i]*(j-1)-sum[j-1]);
}

signed main(){
	freopen("crystal.in","r",stdin); freopen("crystal.out","w",stdout);
	int n;long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	
	int ans=0;
	for(int i=1;i<=n;i++){
		dp[i]=1ll*i*a[i]-sum[i];
		//cout<<dp[i]<<' ';
	}
	//cout<<endl;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		int mid;
		while(l<=r){
			mid=(l+r)/2;
			int k=getcost(i,mid);
			if(k>m)	l=mid+1;
			else r=mid-1,ans=max(ans,i-mid+1);
		}
	}
	cout<<ans<<endl;
	return 0;
	
}
