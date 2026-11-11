#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define pii pair<int, int>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define pll pair<long long, long long>
#define debug(x) cerr << #x << ": " << (x) << "\n"
#define ll long long
#define ull unsigned long long
#define uint unsigned int
using namespace std;
int n;
ll d, a[2000007];
void solve(){
	cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> a[i];
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int C, T;
	cin >> C >> T;
	while(T--) solve();
}

