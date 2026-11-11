#include <bits/stdc++.h>
using namespace std;
int n, d, cnt = 0;
int minlen;
vector<int> x;
void dfs(int u, int v, int len){
	if(len > minlen) return;
	if(u == v && len <= minlen){
		cnt++;
		return;
	}
	for(int i = 1; i <= d; i++){
		if(u + i > v) break;
		bool flag = 0;
		for(auto tmp : x){
			if(u + i == tmp) flag = 1;
		}
		if(!flag) continue;
		dfs(u + i, v, len + 1);
		cerr << "dfs(" << u + i << ", " << v << ", " << len + 1 << endl;
	}
	return;
} 
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--){
		int ans = 0;
		cin >> n >> d;
		x.resize(n);
		for (auto& tmp : x) cin >> tmp;
		for (int i = 0; i < n - 1; i++){
			for (int j = i + 1; j < n; j++){
				minlen = ceil((j - i) / d);
				cnt = 0;
				cerr << i << " " << j << " " << 0 << endl;
				dfs(i, j, 0);
				if(cnt == 2) ans++;
			} 
		}
		cout << ans << "\n"; 
	}
	return 0;
}

