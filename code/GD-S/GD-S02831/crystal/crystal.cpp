#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N=500050;
ll n,m;
ll a[N];
void solve(){
	cin >> n >> m;
	for(ll i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+1+n);
	ll i;
	for(i=2;i<=n;i++){
		m-=(i-1)*(a[i]-a[i-1]);
		if(m<0)break;
	}
	if(m>=0){
		if(m%n==0)cout << i;
		else cout << i-1;
		return;
	}
	cout << i-1;
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	return 0;
}
