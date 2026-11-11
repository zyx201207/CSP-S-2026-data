#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 501000; 
int n;
ll a[N], s[N], m;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int L = 1, R = i + 1;
		while(L + 1 < R){
			int M = (L + R) / 2;
			if(1LL * a[i] * (i - M + 1) - (s[i] - s[M - 1]) <= m)
				R = M;
			else
				L = M;
		}
		ans = max(ans, i - R + 1);
	}
	cout << ans << '\n';
	return 0; 
}
