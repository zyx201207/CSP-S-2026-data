#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;
int a[N], b[N];
int pos[N], ans[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int cnt;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		pos[a[i]] = max(pos[a[i]], i);
	}
	for(int i = n ; i >= 1 ; i--){
		cnt = i;
		for(int j = i ; j <= n ; j = cnt){
			ans[a[j]]++;
			if(pos[a[j]] > cnt) cnt = pos[a[j]] + 1;
			else cnt++;
		}
	}
	for(int i = 1 ; i <= m ; i++) cout << ans[i] << " ";
	return 0;
}
