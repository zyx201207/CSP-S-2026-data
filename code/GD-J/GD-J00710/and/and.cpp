#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;ll a[2000005];
bool cmp(ll a2,ll b2){
	return a2 > b2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(ll i = 1;i<=n;++i){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	ll ans;
	for(int i = 2;i<=m;++i){
		if(i == 2)
			ans = (a[i-1] & a[i]);
		else
			ans = (ans & a[i]);
	}
	cout << ans;
	return 0;
}
