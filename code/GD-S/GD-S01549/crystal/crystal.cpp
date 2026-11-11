#include<bits/stdc++.h>
using namespace std;
long long a[500050],sum[500050];
long long getsum(long long l,long long r){
	return sum[r]-sum[l-1];
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	sum[0]=0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1;
	long long ans=0;
	for (int r=1;r<=n;r++){
		long long cnt=0;
		if(m+getsum(l,r)>=a[r]*(r-l+1)) cnt=r-l+1;
		else{
			while(m+getsum(l,r)<a[r]*(r-l+1)) l++;
			cnt=r-l+1;
		} 
		ans=max(ans,cnt);
	}
	cout<<ans<<'\n';
	return 0;
} 
