#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 3e5 + 10;
int n, m;
int a[N], ans[M];
vector <int> t(N);
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int k = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n ;j++){
			int f = k + 1;
			for(int x = 1; x <= k; x++){
				if(t[x] == a[j]){
					f = x;
					break;
				}
			}
			for(int x = f; x <= k; x++) t[x] = 0;
			k = f - 1;
			t[++k] = a[j];
		}
		for(int j = 1; j <= k; j++){
			ans[t[j]]++;
			t[j] = 0;
		}
		k = 0;
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
	return 0;
}

