#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
using namespace std;
const int maxn = 2e5 + 5;
int n, m, sum, ans = -1, a[maxn], vis[maxn];
vector<int> ve;
bool cmp(int a, int b) {
	return a > b;
}
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	for(int i = 30; i >= 0; i--) {
		sum = 0;
		for(int j = 0; j < ve.size(); j++) ve.clear();
		for(int j = 1; j <= n; j++) {
			if(a[j] & (1 << i) && !vis[j]) sum++;
			else if(!(a[j] & (1 << i)) && !vis[j]) ve.push_back(j); 
		}
		if(sum >= m) {
			for(int j = 0; j < ve.size(); j++) vis[ve[j]] = 1;
			if(m == sum) break;
		}
	} 
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			if(ans == -1) ans = a[i];
			else ans &= a[i]; 
		}
	}
	cout << ans << "\n";
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int oT_To = 1;
	//cin >> oT_To;
	while(oT_To--) solve();
	return 0;
}

