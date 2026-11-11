#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int P(1e9+7);
ll kuaishumi(ll x,ll b){
	if(!b)return 1;
	ll t(kuaishumi(x*x%P,b/2));
	if(b&1)t=t*x%P;
	return t; 
} 
const int MXN(1e6+6);
ll n,m;
ll a[MXN];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0); 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	// I trust ccf big asmple
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int l=1;
	ll now=0;
	int res=1;
	for(int r=1;r<=n;r++){
		now+=(r-l)*(a[r]-a[r-1]);
		while(now>m)
			now-=a[r]-a[l++];
		res=max(res,r-l+1);
	}
	cout<<res;
	return 0;
}
