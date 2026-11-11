#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;

int n,m,a[N],f[N],sum[N],ans;
bool check(int x){
	for(int i(x);i<=n;++i){
		int res=sum[i]-sum[i-x]+x*(a[n]-a[i]);
		if(res+m>=0){
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i(1);i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	f[n]=0;
	for(int i(n-1);i>=1;--i){
		f[i]=f[i+1]+a[i]-a[i+1];
	}
	for(int i(1);i<=n;++i){
		sum[i]=f[i]+sum[i-1];
	}
	int l=1,r=n,mid=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=max(ans,mid);
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
