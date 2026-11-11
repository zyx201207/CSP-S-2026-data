#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int MAX = 5e5 + 10;
int n, m;
ll a[MAX], ans = 1, ans1 = 1;

int main(){
	cin.tie(0)->ios::sync_with_stdio(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	ll cnt = 0, ccnt = 0;
	int p = 1, lst = 1;
	a[n + 1] = a[n];
	while(p <= n){
		if(m >= (a[p + 1] - a[p]) * p){
			cnt += a[p + 1] - a[p];
			++ans;
			m -= (a[p + 1] - a[p]) * p;
			++p;
		}else break;
	}
	ans1 = ans;
	ll m1 = m;
	for(int i = p; i <= n; ++i){
		if(m >= (a[i + 1] - a[i]) * ans){
			m -= (a[i + 1] - a[i]) * ans;
			++ans;
		}else{
			while(m + a[i] - a[lst] < (a[i + 1] - a[i]) * ans && ans > 0){
				m += a[i] - a[lst];
				--ans;
				++lst;
			}
			if(m + a[i] - a[lst] >= (a[i + 1] - a[i]) * ans && ans > 0){
				m = m + a[i] - a[lst] - (a[i + 1] - a[i]) * ans;
				++lst;
			}else{
				ans = 1;
				m = m1;
				lst = i;
			}
		}
		ans1 = max(ans1, ans);
	}
	cout << ans1;
	return 0;
}
