#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define ll long long
#define pii pair<ll, ll>
#define fi first
#define se second
#define pb push_back
using namespace std;
#define N 2000005
#define inf 0x3f3f3f3f

ll c, n, d, a[N], cnt[N], ds[N], nxt[N], pre[N], l[N], r[N], s[N];

void solution(ll tas) {
	cin >> n >> d;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) nxt[i] = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
	rep(i, 1, n) pre[i] = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
	//rep(i, 1, n) cout << pre[i] << " "; cout << "\n";
	ll res = 0;
	rep(i, 1, n) {
		ll t = i + 1;
		rep(j, 1, n) cnt[j] = (i == j), ds[j] = l[j] = r[j] = 0;
		rep(j, 1, n) s[j] = (i == j);
		rep(j, i, n) while(t <= nxt[j]) ds[t] = ds[j] + 1, t ++;
		ll lst = i; l[0] = r[0] = i;
		rep(j, i + 1, n) {
			if(l[ds[j]] <= lst) l[ds[j]] = j;
			r[ds[j]] = j;
			ll x = max(l[ds[j] - 1], pre[j]);
			//cout << x << " ";
			cnt[j] = s[r[ds[x]]] - s[x - 1];
			s[j] = s[j - 1] + cnt[j];
			if(j == nxt[j]) lst = j;
		}
		//cout << "\n";
		rep(j, i + 1, n) res += (cnt[j] == 2);
		//rep(j, 1, n) cout << ds[j] << " "; cout << "\n";
		//rep(j, 1, n) cout << cnt[j] << " "; cout << "\n";
		//rep(j, 1, n) cout << s[j] << " "; cout << "\n\n";
	}
	cout << res << "\n";
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tas = 1; cin >> c >> tas;
	rep(i, 1, tas) solution(i);
	return 0;
}

/*
15:35 开题
15:59 感觉四个连在一起的结构很重要
16:03 发现了更通用的结构，把数轴分成若干条链，不，不是链，整体是森林
16:13 感觉没什么前途 
16:24 不太会，先去看看 D 的部分分，换换脑子 
16:40 感觉 D 是个树形 dp，但又不太像，因为需要 O(n) 做
*/
