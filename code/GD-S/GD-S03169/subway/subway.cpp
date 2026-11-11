#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 510;
const int maxm = 5e5 + 10;
int w[maxm];
long long dis[maxn][maxn]; 
//dis[i][j]: distance between line i and line j
struct station{
	vector<int> line; //the lines that pass through s[i] 
	vector<long long> t; //distance from s[i] to the line
}s[maxm];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	memset(dis, 0x3f, sizeof(dis));
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> w[i];
		s[i].line.push_back(0);
		s[i].t.push_back(0);
	}
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++){
			int a, t;
			cin >> a >> t;
			s[a].line.push_back(i);
			s[a].t.push_back(t);
		}
	}
	//pre_deal
	for (int i = 1; i <= n; i++)
		dis[i][i] = 0;
	for (int i = 1; i <= m; i++){
		auto sta = s[i];
		for (int j = 1; j < sta.line.size(); j++){
			for (int k = j + 1; k < sta.line.size(); k++){
				int x = sta.line[j], y = sta.line[k];
				dis[x][y] = dis[x][y] = min(dis[x][y], sta.t[j] + sta.t[k]);
				//cout << i << " " << j << " " << k << " " << dis[x][y] << endl;
			}
		}
	}
	//floyd
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				if (dis[i][k] + dis[k][j] < dis[i][j]){
					dis[i][j] = dis[j][i] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
	//query
	for (int r = 1; r <= q; r++){
		int x, y;
		cin >> x >> y;
		long long ans = 1e18;
		for (int i = 1; i < s[x].line.size(); i++){
			for (int j = 1; j < s[y].line.size(); j++){
				long long cur = w[x] + w[y];
				cur += s[x].t[i];
				cur += s[y].t[j];
				//cout << cur << endl;
				cur += dis[s[x].line[i]][s[y].line[j]];
				ans = min(ans, cur);
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
//16:00 read t2
//A: 20pts, B: 24pts
//17:05 come up with AC idea!
//18:02 done but wrong answer

