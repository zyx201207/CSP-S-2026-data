#include <bits/stdc++.h>
using namespace std;
long long n,a[514114],s[514114],m,now,ans;
bool check(long long mid){
	for(long long i=mid;i<=n;++i){
		if(m>=s[i]-s[i-mid]-(a[n]-a[i])*mid) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	s[0]=0;
	for(int i=1;i<=n;++i) s[i]=s[i-1]+a[n]-a[i];
	/*for(int i=1;i<=n;++i) cout<<s[i]-s[i-1]<<' ';
	cout<<'\n';*/
	long long L=1,R=n,mid;
	while(L<=R){
		mid=(L+R)>>1;
		if(check(mid)){
			ans=mid;
			L=mid+1;
		}
		else R=mid-1;
	}
	cout<<ans;
	return 0;
}
