#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e6 + 5;
ll x[MAXN];
int pre[MAXN], nxt[MAXN], minn[MAXN], cnt[MAXN];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, T;
	cin >> c >> T;
	while(T--){
		int n;
		ll d;
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i];
		if(n == 1){
			cout << "0\n";
			continue;
		}
		if(c == 11 || c == 12){
			ll stp = d / (x[2] - x[1]);
			if(stp <= 1){
				cout << "0\n";
				continue;
			}
			int ans = 0;
			for(int i = 1; i <= n; i++) if(i + 2 * stp - 1 <= n) ans++;
			cout << ans <<"\n";
			continue;
		}
		int it = 1;
		for(int i = 2; i <= n; i++){
			while(it < i && x[i] - x[it] > d) it++;
			pre[i] = it;
		}
		ll ans = 0;
		for(int s = 1; s <= n; s++){
			for(int i = s + 1; i <= n; i++){
				if(pre[i] <= s) minn[i] = 1, cnt[i] = 1;
				else{
					if(pre[i] == i){
						minn[i] = 1e9, cnt[i] = 0;
					}else{
						minn[i] = minn[pre[i]] + 1;
						cnt[i] = cnt[pre[i]];
						if(pre[i] + 1 < i && minn[pre[i] + 1] == minn[pre[i]]) cnt[i] += cnt[pre[i] + 1];
						if(pre[i] + 2 < i && minn[pre[i] + 2] == minn[pre[i]]) cnt[i] += cnt[pre[i] + 2];
						if(cnt[i] > 2) cnt[i] = 3;
					}
				}
				if(cnt[i] == 2) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
