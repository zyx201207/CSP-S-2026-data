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

const int N = 2e5+5, M = 40;

int n, m, a[N];
int ans;
bool vis[N];

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 29; i >= 0; i--){
		int sum = 0;
		for(int j = 1; j <= n; j++){
			if(vis[j]) continue;
			if(a[j] & (1 << i)) sum++;
		}
		if(sum >= m){
			ans |= (1 << i);
			for(int j = 1; j <= n; j++){
				if(!(a[j] & (1 << i))) vis[j] = 1;
			}
		}
	}
	cout << ans << "\n";
	
	return 0;
}
