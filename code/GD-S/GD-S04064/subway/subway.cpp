#include<bits/stdc++.h>
using namespace std;

#define int long long
//i 条线，输入 (x,y) 表示该线地铁站x从台到厅的花费为y
//地铁站x vector 严肃换乘 20 * 20 应该问题不大
const int M = 5e5+10, XL = 510;
int cesd,n,m,d,q;

int w_k2ti[M]; 
vector<pair<int,int>>hc[M];

int x2x[XL][XL];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin>>cesd>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) {
		cin>>w_k2ti[i];
	}
	
	for (int i=1;i<=n;i++) {
		int ki;
		cin>>ki;
		for (int j=1;j<=ki;j++) {
			int x,y;cin>>x>>y;
			hc[x].push_back({i,y});
		}
	}
	
	memset(x2x,0x3f,sizeof x2x);
	for (int i=1;i<=n;i++) x2x[i][i] = 0;
	for (int i=1;i<=m;i++) {
		int kk = hc[i].size();
		for (int j=0;j<kk;j++) {
			for (int k=j+1;k<kk;k++) {
				x2x[hc[i][j].first][hc[i][k].first] = min(x2x[hc[i][j].first][hc[i][k].first], hc[i][j].second + hc[i][k].second);
				x2x[hc[i][k].first][hc[i][j].first] = min(x2x[hc[i][k].first][hc[i][j].first], hc[i][j].second + hc[i][k].second);
			}
		}
	}
	
	for (int k=1;k<=n;k++) {
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				x2x[i][j] = min(x2x[i][j], x2x[i][k] + x2x[k][j]);
			}
		}
	}
	
	for (int i=1;i<=q;i++) {
		int x,y; cin>>x>>y;
		
		int ans = 1e18;
		for (int xian1=0;xian1<hc[x].size();xian1++) {
			for (int xian2=0;xian2<hc[y].size();xian2++) {
				int stxl = hc[x][xian1].first, edxl = hc[y][xian2].first;
//				cout << stxl << ' ' << edxl << ' ' << x2x[stxl][edxl] << endl;
				ans = min(ans, w_k2ti[x] + w_k2ti[y] + hc[x][xian1].second + hc[y][xian2].second + x2x[stxl][edxl]);
			}
		}
		
		cout << ans << '\n';
	}
	return 0;
}
