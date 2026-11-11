#include  <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
using namespace std;

const int maxn = 2e6 + 10;
const int inf = INT_MAX / 2;

int n, m, a[maxn], ans;
int cnt[maxn];

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen ("add.in", "r", stdin);
	//freopen ("add.out", "w", stdout);
    
    cin >> n >> m;
    for (int i = 1; i <= n ;i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 1; i <= n ;i++)

	return 0;
}
