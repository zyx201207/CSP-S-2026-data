#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll n,m;
ll a[200010];

bool cmp(ll x,ll y){
	return x>y;
}

void solve(){
	cin >> n >> m;
	for(ll i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+n+1,cmp);
	if(m==1)cout << a[1];
	else if(m==2){
		cout << max({a[1]&a[2],a[2]&a[3],a[3]&a[1]});
	}
	else{
		int ans=a[1];
		for(int i=2;i<=m;i++)ans&=a[i];
		cout << ans;
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	solve();
	return 0;
}
