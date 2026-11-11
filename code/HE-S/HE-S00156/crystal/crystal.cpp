#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
ll n,m,a[N];
bool check(ll mid){
	ll cnt=0;
	for(ll i=1;i<=n&&a[i]<=mid;i++){
		ll tmp=abs(mid-a[i]);
		cnt+=tmp;
	}
	return cnt<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	ll L=1e18,R=-1e18;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		L=min(L,a[i]);
		R=max(R,a[i]);
	}
	sort(a+1,a+1+n);
	ll l=L,r=R;
	while(l+1!=r){
		ll mid=l+r>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
		if(a[i]<=l) ans++;
	cout<<ans<<'\n';
	return 0;
}
