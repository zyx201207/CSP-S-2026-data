#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
using ll=long long;
ll a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;cin>>n;
	ll m;cin>>m;
	for (int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
	ll l=1,ans=1;
	for (ll r=1;r<=n;++r){
		while ((r-l+1)*1ll*a[r]-(s[r]-s[l-1])>m&&l<=r)l++;
		ans=max(ans,r-l+1);
//		cout<<r<<" "<<l<<'\n'; 
	}
	cout<<ans;
	return 0;
}
