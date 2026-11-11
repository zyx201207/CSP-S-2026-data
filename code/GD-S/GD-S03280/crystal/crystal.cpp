#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long Long;
typedef unsigned long long ULong;

const int N = 500000;
const Long M = 1e18;
const Long INF = 0x3f3f3f3f3f3f3f3f;
const Long MOD = 998244353; 

int n;
Long m;
Long a[N+1];

inline void solve(){
	cin >> n >> m;
	
	int ans = 0;
	
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	sort(a+1, a+1 + n); 
	for(int i = 1; i <= n; ++i){
		int l = 1, r = i;
		while(l < r){
			int mid = (l + r + 1) >> 1;
			bool condition = (a[i] * mid - (a[i-1] - a[i-mid-1])) <= m;
			
			if(condition){
				l = mid;
			}else{
				r = mid - 1;
			}
		}
		ans = max(ans, l+1);
		a[i] += a[i-1];
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

//	int t; cin >> t; while(t--)
	{
		solve();
	}

	return 0;
}
