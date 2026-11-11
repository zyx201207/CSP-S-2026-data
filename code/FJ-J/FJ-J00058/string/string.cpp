#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int N = 2e5 + 5;

struct Seq {
	int a; char c;
} s[N];

int n;
stack<Seq> stk;

void solve() {
	cin >> n;
	ll SUM = 0;
	for(int i = 1; i <= n; i++) {
		cin >> s[i].a >> s[i].c;
		stk.push(s[i]); SUM += s[i].a;
	}
	ll ans = 0, tot = 0;
	for(int i = 1; i <= n; i++) {
		ll res = 0, sum = 0;
		if(tot + s[i].a <= SUM / 2) {
			while(sum < s[i].a) {
				if(sum + stk.top().a <= s[i].a) {
					if(stk.top().c == s[i].c) {
						sum += stk.top().a, stk.pop();
					}
					else {
						res += stk.top().a, sum += stk.top().a, stk.pop(); 
					}
				} else {
					if(stk.top().c == s[i].c) {
						int l = stk.top().a - (s[i].a - sum);
						stk.pop(); stk.push(Seq{l, s[i].c});
					} else {
						res += s[i].a - sum;
						char ch = stk.top().c; int l = stk.top().a - (s[i].a - sum);
						stk.pop(); stk.push(Seq{l, ch});
					}
					sum = s[i].a;
				}
			}
			tot += sum, ans += res;
		} else {
			ll tmp = (SUM / 2 - tot);
			while(sum < tmp && !stk.empty()) {
				if(sum + stk.top().a <= tmp) {
					if(stk.top().c == s[i].c) sum += stk.top().a, stk.pop();
					else res += stk.top().a, sum += stk.top().a, stk.pop(); 
				} else {
					if(stk.top().c == s[i].c) {
						int l = stk.top().a - (tmp - sum);
						stk.pop(); stk.push(Seq{l, s[i].c});
					} else {
						res += tmp - sum;
						char ch = stk.top().c; int l = stk.top().a - (tmp - sum);
						stk.pop(); stk.push(Seq{l, ch});
					}
					sum = tmp;
				}
			}
			ans += res; break;
		}
	}
	cout << ans << endl;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T = 1;
//	cin >> T;
	while(T--) solve();

	return 0;
}

