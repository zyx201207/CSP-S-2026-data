#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int c, T;
int n; ll d;
ll x[2000010];

namespace sub_1_10{
	int dis[5010][5010], cnt[5010][5010];
	void work(){
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= n; j ++){
				dis[i][j] = 0x3fffffff;
				cnt[i][j] = 0;
			}
		}
		int ans = 0;
		for(int s = 1; s < n; s ++){
			dis[s][s] = 0;
			cnt[s][s] = 1;
			for(int t = s + 1; t <= n; t ++){
				int p = lower_bound(x + 1, x + n + 1, x[t] - d) - x;
				p = max(s, p);
				if(p == t){ cnt[s][t] = 0; continue; }
				dis[s][t] = dis[s][p] + 1;
				for(int i = p; i < min(p + 3, t); i ++) cnt[s][t] += (dis[s][i] + 1 == dis[s][t]) * cnt[s][i];
 				ans += (cnt[s][t] == 2);
			}
		}
		cout << ans << endl;
	}
}

namespace sp_a{
	void work(){
		if(n == 1){ cout << 0 << endl; return; }
		ll dis = x[2] - x[1];
		if(dis * 2 > d){ cout << 0 << endl; return; }
		int mx = min(1ll * n, d / dis);
		ll ans = max(0, n - 2 * mx + 1);
		cout << ans << endl;
	}
}

int main(){
#ifndef LOCAL_TEST
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
#endif
	cin >> c >> T;
	while(T --){
		cin >> n >> d;
		for(int i = 1; i <= n; i ++) cin >> x[i];
		if(c <= 10) sub_1_10::work();
		else if(c <= 12) sp_a::work();
		else cout << 0 << endl;
	}
}