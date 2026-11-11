#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 3e5 + 10;
int n, m, a[N], ans[M], v[N], w[M], f, x[M];
unordered_map<int, int> p;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] > a[i - 1]) f = 1;
		v[i] = w[a[i]];
		w[a[i]] = i;
	}
	if(!f){
		for(int i = 1; i <= m; i++) cout << w[i] << ' ';
		return 0;
	}
	for(int i = 1; i <= n; i++){
		p.clear();
		for(int j = i; j <= n; j++){
			if(v[j] >= i && !p[a[j]]){
				for(int k = v[j]; k <= j; k++) p[a[k]]++;
			}
			p[a[j]] = 0;
		}
		for(int j = i; j <= n; j++){
			//cout << a[j] << ' ' << p[a[j]] << ';';
			if(!p[a[j]]) ans[a[j]]++;
			p[a[j]]++;
		}
		//cout << endl;
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
	return 0;
}

