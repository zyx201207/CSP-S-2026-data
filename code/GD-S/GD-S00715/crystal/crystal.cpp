#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	ll ans=1,js=0;
	for (int i=1,j=2;j<=n;j++){
		js+=(a[j]-a[j-1])*(j-i);		
		while(js>m){
			js-=a[j]-a[i];
			i++;
		}
		ans=max(ans,1LL*(j-i+1));
	}
	cout<<ans;
	return 0;
}
