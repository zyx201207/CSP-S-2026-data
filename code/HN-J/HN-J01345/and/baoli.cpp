#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define pii pair<int, int>
#define MP make_pair
#define fi first
#define se second
#define __low lower_bound
#define __upp upper_bound
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 30;

int n, m, a[N];
bool vis[N];
int ans;

void check(){
	int now = (1 << 30) - 1;
	for(int i = 1; i <= n; i++){
		if(vis[i]) now &= a[i];
	}
	ans = max(ans, now);
}

void dfs(int x, int y){
	if(y == m){
		check();
		return;
	}
	if(x > n) return;
	vis[x] = 1;
	dfs(x+1, y+1);
	vis[x] = 0;
	dfs(x+1, y);
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("baoli.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dfs(1, 0);
	cout << ans << "\n"; 
	
	return 0;
}
