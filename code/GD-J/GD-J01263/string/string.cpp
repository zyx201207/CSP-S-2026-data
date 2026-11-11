#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e5+10;
ll n,ans,a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i]>>c[i];
	ll l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]) ans+=min(a[l],a[r]);
		if(a[l]<a[r]){
			a[r]-=a[l];
			l++;
		}else{
			a[l]-=a[r];
			r--;
		}
		if(!a[l]) l++;
		if(!a[r]) r--;
	}
	cout<<ans;
	return 0;
}
