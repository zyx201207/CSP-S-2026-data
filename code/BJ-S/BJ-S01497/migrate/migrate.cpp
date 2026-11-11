#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;;
int n, T, c;
long long x[N], dis, D, ab, ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>c>>T;
	while(T--) {
		cin>>n>>dis;
		for(int i=1;i<=n;i++) {
			cin>>x[i];
		}
		D = x[2] - x[1];
		if(D*2 > dis) {
			cout<<0<<'\n';
			continue;
		}
		ab = dis / D, ans = 0;
		for(int i=1;i<n-ab;i++) {
			if(i+ab*2-1 <= n) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
