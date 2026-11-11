#include <bits/stdc++.h>
using namespace std;
struct station{
	int w;
	vector <int> subway[2];
} sta[500050];
vector <int> sub[550][2];
int main(){
	freopen ("subway.in", "r",stdin);
	freopen ("subway.out", "w",stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> sta[i].w;
	}
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++){
			int a, t;
			cin >> a >> t;
			sub[n][0].push_back(a);
			sub[n][1].push_back(t);
			sta[a].subway[0].push_back(n);
			sta[a].subway[1].push_back(t);
		}
	}
	for (int r = 1; r <= q; r++){
		queue < int > Q[3];
		int x, y;
		long long ans = 0, down = 1009000000000;
		cin >> x >> y;
		ans = sta[x].w + sta[y].w;
		bool cmp[500050] = {0};
		Q[0].push(x);
		Q[1].push(ans);
		cmp[x] = true;
		while (!Q[0].empty()){
			int now = Q[1].front();
			Q[1].pop();
			int its = Q[0].front();
			Q[0].pop();
			int len = sta[its].subway[0].size();
			for (int i = 0; i < len; i++){
				int them = sta[its].subway[0][i];
				int tmp = sub[them][0].size();
				for (int j = 0; j < tmp; j++){
					int kk = sub[them][0][j];
					if(cmp[kk]) continue;
					long long temp = now + sub[them][1][j] + sta[its].subway[1][i]; 
					if(kk == y){
						down = min(down, temp);
						continue;
					}
					Q[0].push(kk);
					Q[1].push(temp);
					cmp[kk] = true;
				}
			}
		}
		cout << down << endl;	
	}
	fclose (stdin);
	fclose(stdout);
	return 0;
}
