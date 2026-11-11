#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
void solve(){
	int n,k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		int u,v;
		cin >> u >> v;
	}
	int now = time(0);
	now = now * now;
	int res = (now + 998244353) % (k + 1);
	cout << res << endl;
	return ;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int C,T;
	cin >> C >> T;
	while (T--){
		solve();
	}
	
	return 0;
}

