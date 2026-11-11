#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define ll long long
#define pii pair<ll, ll>
#define fi first
#define se second
#define pb push_back
using namespace std;
#define N 500005

ll n, m, a[N], s[N];

void solution(ll tas) {
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	rep(i, 1, n) s[i] = s[i - 1] + a[i];
	ll res = 1;
	rep(i, 1, n) {
		ll l = 1, r = i - 1, t = 1;
		while(l <= r) {
			ll mid = (l + r) >> 1;
			if((i - mid) * a[i] - (s[i - 1] - s[mid - 1]) <= m) r = mid - 1, t = i - mid + 1;
			else l = mid + 1;
		}
		res = max(res, t);
	}
	cout << res << "\n";
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tas = 1; // cin >> tas;
	rep(i, 1, tas) solution(i);
	return 0;
}

/*
14:35 开题
14:45 写完了，样例全过
15:49 C 题想了一半，缓一下脑子，结果发现 A 题的 corner case 了，差点挂了。 
*/
