#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], b[500005], ans[300005], c[500005];
vector<int> v[300005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i], v[a[i]].push_back(i), b[i] = a[i], c[i] = v[a[i]].size() - 1;
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			ans[b[j]]++;
			int v1 = v[b[j]].size() - 1;
			if(v1 > c[j]){
				j = v[b[j]][v1];
			}
		}
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
