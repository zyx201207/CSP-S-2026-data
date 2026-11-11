#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long Long;
typedef unsigned long long ULong;

const int N = 200000;
const Long MOD = 998244353;
const Long INF = 0x3f3f3f3f3f3f3f3f;

int n;
Long a[N];
char c[N];

inline void solve(){
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> a[i] >> c[i];
	}
	
	Long l = 0, r = n-1;
	Long ans = 0;
	
	while(l < r){
		Long check_length = min(a[l], a[r]);
		if(c[l] != c[r]){
			ans += check_length;
		}
		if((a[l] -= check_length) <= 0){
			++l;
		}
		if((a[r] -= check_length) <= 0){
			--r;
		}
	}
	
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
//	int t; cin >> t; while(t--)
	{
		solve();
	}
	
	return 0;
}
