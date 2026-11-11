#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
using namespace std;
ll n,m,a[500005],f[500005],ans=1,l=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	f[1]=0;
	for(ll i=2;i<=n;++i){
		f[i]=f[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	for(ll i=2;i<=n;++i){
		while(f[i]-f[l]-(l-1)*(a[i]-a[l])>m){
			++l;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}

