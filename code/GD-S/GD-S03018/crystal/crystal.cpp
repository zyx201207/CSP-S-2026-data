#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define debug(x) cerr << #x << " = " << (x) << endl

using namespace std;

const int maxn = 5e5 + 10;

ll a[maxn], qzh[maxn];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i){
		qzh[i] = qzh[i-1] + a[i];
	}
	int ans = 0;
	int l, r, mid;
	for(int i = n; i > 1; --i){
		l = 1;
		r = i - 1;
		if(a[i-1] + m < a[i]){
			continue;
		}
		while(l <= r){
			mid = (l + r) >> 1;
			if(qzh[i-1] - qzh[mid-1] + m >= a[i] * (ll)(i - mid)){
				r = mid - 1;
			}else{
				l = mid + 1;
			}
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
}
