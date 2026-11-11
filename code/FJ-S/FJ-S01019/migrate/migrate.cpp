#include<bits/stdc++.h>
using namespace std;

int cid, t;

int main(){
	
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> cid >> t;
	
	while(t--){
		
		int n; long long d, ans = 0;
		cin >> n >> d;
		
		vector<long long> x(n + 1);
		for(int i = 1; i <= n; i++) cin >> x[i];
		
		vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				for(int k = i + 1; k <= j - 1; k++)
					if(x[k] - x[i] <= d && x[j] - x[k] <= d) f[i][j]++;
			}
		}
		
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				vector<int> path;
				int cnt = 0;
				int k = i;
				while(k < j){
					path.push_back(k);
					long long pos = x[k];
					while(k < j && x[k + 1] - pos <= d) k++;
					if(x[k] == pos) goto NO_PATH;
				}
				path.push_back(j);
				for(int idx = 1; idx < path.size() - 1; idx++){
					cnt += f[path[idx - 1]][path[idx + 1]] - 1;
					if(cnt >= 2) break;
				}
				if(cnt == 1) ans++;
				NO_PATH: ;
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}
