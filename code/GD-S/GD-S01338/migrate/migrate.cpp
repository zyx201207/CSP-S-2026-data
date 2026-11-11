#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6 + 9;
const ll llmax = 1e18;
ll a[maxn], b[maxn];
int nxt[maxn];
int l[maxn], r[maxn];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, t;
	cin >> c >> t;
	if(c == 11 || c == 12){
		while(t--){
			int n;
			ll d;
			cin >> n >> d;
			if(n == 1){
				cout << 0 << "\n";
				continue;
			}
			for(int i = 1;i <= n;i++){
				cin >> b[i];
			}
			ll cha = b[2] - b[1];
			if(d >= (cha << 1ll)){
				ll val = 2 * (d / cha) - 1;
				cout << max((ll)0, (ll)n - val) << "\n";
			}
			else{
				cout << 0 << "\n";
			}
		}
		return 0;
	}
	while(t--){
		int n;
		ll d;
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> b[i];
			a[i - 1] = b[i] - b[i - 1];
			nxt[i] = l[i] = r[i] = 0;
		}
		n--;
		a[0] = llmax;
		for(int i = 1;i <= n;i++){
			int j = i;
			ll sum = 0;
			while(j <= n && sum + a[j] <= d){
				sum += a[j];
				j++;
			}
			if(j > i && sum + a[i - 1] > d) nxt[i] = j - 1;
		} 
		for(int i = 1;i <= n;i++){
			int st = i, cnt = 0;
			while(nxt[st] > 0){
				cnt++;
				st = nxt[st] + 1;
				l[st] = max(l[st], cnt);
			}
			r[i - 1] = cnt;
		}
		ll ans = 0;
		for(int i = 1;i <= n;i++){
			int j = nxt[i];
			if(j == 0 || j == i) continue;
			int v = nxt[j];
			if(v == 0) continue;
			ans += (ll)(l[i] + 1) * (v - j - 1);
			ans += (ll)(l[i] + 1) * (r[v] + 1);
		}
		cout << ans << "\n"; 
	}
	
	return 0;
}

