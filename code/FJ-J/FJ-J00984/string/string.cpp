#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ax[200005];char ay[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,l=0,ans=0;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ax[i]>>ay[i];
		l+=ax[i];
		ax[i]=l;
	}
	l/=2;
	for(ll i=1;i<=l;i++){
		ll t=lower_bound(ax+1,ax+1+n,i)-ax;
		ll l=lower_bound(ax+1,ax+1+n,ax[n]+1-i)-ax;
		if(ay[t]!=ay[l]) ans++;
	}
	cout<<ans;
	return 0;
}