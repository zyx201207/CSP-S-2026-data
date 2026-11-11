#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
typedef long long Long;
typedef unsigned long long ULong;
typedef unsigned int UInt;

const int N = 200000;
const int M = N;
const int MAX_BIT = 1 << 29;
const Long MOD = 998244353;
const Long INF = 0x3f3f3f3f3f3f3f3f;

int n, m;
UInt a[N];
vector<int> bucket[30];
bool alive[N];

inline void solve(){
	cin >> n >> m;
	fill(alive, alive+n, true);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		for(int j = 29; j >= 0; --j){
			if(a[i] & UInt(1 << j)) bucket[j].push_back(i);
		}
	}
	
	UInt ans = 0;
	for(int j = 29; j >= 0; --j){
		int cnt = 0;
		for(int vi: bucket[j]){
			if(alive[vi]) ++cnt;
			else a[vi] = 0;
		}
		if(cnt >= m){
			ans |= (1 << j);
			// start killing...
			fill(alive, alive+n, false);
			for(int vi: bucket[j]){
				if(a[vi]) alive[vi] = true;
			}
		}
	}
	
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
//	int t; cin >> t; while(t--)
	{
		solve();
	}
	
	return 0;
}
