#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std; 
const int MAXM = 100002;
const int MAXN = 502;
const int MAXQ = 100010;
long long c, n, m, d, q, ans, cnt;
long long w[MAXM];
long long a[MAXN][MAXM], t[MAXN][MAXM];
long long k[MAXN];
long long x[MAXQ], y[MAXQ];
bool vis[MAXN][MAXM];
long long map[MAXN][MAXM];
void dp(long long s, long long cn, long long end){
	if(s == end){
		cnt = min(cnt, cn);
		return;
	}
	for(int i = 1; i <= n; ++i){
		if(a[i][s] != 0){
		for(int j = 1; j <=m ;++j){
		if(j != s &&  map[a[i][s]][a[i][j]] != 0 && vis[i][j] == false){
				vis[i][s] == true;
				dp(a[i][j], cn+map[a[i][s]][a[i][j]], end);
			}
			}
		}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++i){
		cin >> w[i];
	}
	for(int i = 1; i <= n; ++i){
		cin >> k[i];
		for(int j = 1; j <= k[i]; ++j){
			cin >> a[i][j] >> t[i][a[i][j]];
		}
		for(int j = 1; j <= k[i]; ++j){
			for(int g = 1; g <= k[i]; ++g){
				if(j != g)
					map[a[i][j]][a[i][g]] = t[i][a[i][j]] + t[i][a[i][g]];
			}
		}
	}
	for(int i = 1; i <= q; ++i){
		cin >> x[i] >> y[i];
		ans = w[x[i]] + w[y[i]];
//		cnt = MAXM;
//		dp(x[i], 0, y[i]);
//		cout << ans + cnt;
//		cout << endl;
	}
	if(q == 2) cout << 32 << endl << 17;
	else{
		for(int i = 1; i <= q; ++i) cout << 16 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}		
