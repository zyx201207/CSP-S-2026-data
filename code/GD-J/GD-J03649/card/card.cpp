#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
typedef long long Long;
typedef unsigned long long ULong;

const int N = 500000;
const int M = 300000;
const Long MOD = 998244353;
const Long INF = 0x3f3f3f3f3f3f3f3f;

int n, m;
int a[N];
int pos[M+1];
int ans[M+1];
int stored[N];

inline void solve(){
	cin >> n >> m;
	
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		pos[a[i]] = i;
		stored[i] = 1;
	}
	
	for(int i = 0; i < n; ++i){
		ans[a[i]] += stored[i];
		
		int next = pos[a[i]]+1;
		if(next < n) stored[next] += stored[i];
	}
	
	for(int i = 1; i <= m; ++i){
		cout << ans[i] << "\n "[i<m];
	}
}
int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
//	int t; cin >> t; while(t--)
	{
		solve();
	}
	
	return 0;
}
