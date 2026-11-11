#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
const int maxm = 5e5+5,maxn = 505;
int c,n,m,d,q;
int w[maxm];
vector<PII> rd[maxn],plac[maxn];
int floyd[maxn][maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++){
		cin >> w[i];
	}
	
	for (int i = 1;i <= n;i++){
		int ki,a,t;
		cin >> ki;
		for (int j = 1;j <= ki;j++){
			cin >> a >> t;
			rd[i].push_back({a,t});
			plac[a].push_back({i,t});
		}
	}
	
	memset(floyd,0x3f,sizeof(floyd));
	
	for (int j = 1;j <= m;j++){
		int hkys = plac[j].size();
		if (hkys <= 1) continue;
		for (int cf = 0;cf < hkys-1;cf++){
			PII firs = plac[j][cf];
			for (int cn = cf+1;cn < hkys;cn++){
				PII seco = plac[j][cn];
				//cout << j << '>' << cf << ' ' << cn << '\n';
				floyd[seco.first][firs.first] = floyd[firs.first][seco.first] = min(floyd[firs.first][seco.first],firs.second+seco.second);
			}
		}
	}
	
	for (int k = 1;k <= n;k++){
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= n;j++){
				floyd[i][j] = min(floyd[i][j],floyd[i][k] + floyd[k][j]);
			}
		}
	}
	
//	for (int i = 1;i <= n;i++){
//		for (int j = 1;j <= n;j++){
//			cout << floyd[i][j] << ' ';
//		}cout << '\n';
//	}

	for (int i = 1;i <= q;i++){
		int u,v;
		cin >> u >> v;
		int ans = 0x3f3f3f3f3f3f3f3f;
		for (int i = 0;i < plac[u].size();i++){
			PII qf = plac[u][i];
			for (int j = 0;j < plac[v].size();j++){
				PII hf = plac[v][j];
				
				int dis = qf.second+hf.second;
				if (qf.first != hf.first){
					dis += floyd[qf.first][hf.first];
				}
				
				ans = min(ans,dis);
			}
		}
		cout << ans+w[u]+w[v] << '\n';
	}
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
