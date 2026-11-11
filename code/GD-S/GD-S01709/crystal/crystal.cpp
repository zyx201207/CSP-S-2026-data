#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5;
ll n,m,a[N];
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1); 
	ll sub = a[2] - a[1];
	ll cnt = 1,ans = 1;
	while(m && m >= cnt * sub){
		ans++;
		m -= sub * cnt;
		cnt++;
		sub = a[cnt + 1] - a[cnt];
	}
	cout << ans;
}

int main(){
	freopen("crystal1.in","r",stdin); 
	freopen("crystal.out","w",stdout);
	int t = 1;
//	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
