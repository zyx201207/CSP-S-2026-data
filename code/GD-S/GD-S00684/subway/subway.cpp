#include <bits/stdc++.h>
using namespace std;

#define int long long
#define re register 

const int inf = 0x3f3f3f3f3f3f3f3f;
int _,n,m,d,q;
vector<vector<int>> dis;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> _ >> n >> m >> d >> q; 
	const int nm = (n + 2) * m;
	dis.resize(nm + 1);
	for (re int i = 1;i <= nm;++i){
		dis[i].resize(nm + 1);
		for (re int j = 1;j <= nm;++j){
			if (i == j){
				dis[i][j] = 0;
				continue;
			}
			dis[i][j] = inf;
		}
	}
	int w;
	for (re int i = 1;i <= m;++i){
		cin >> w;
		dis[i][i + m] = dis[i + m][i] = min(dis[i][i + m],w);
	}
	for (re int i = 2 * m;i <= (n + 1) * m;i += m){
		int k,a,t,lasta = -1;
		cin >> k;
		while (k--){
			cin >> a >> t;
			if (lasta != -1){
				dis[a + i][lasta + i] = dis[lasta + i][a + i] = 0;
			}
			dis[a + m][a + i] = dis[a + i][a + m] = min(dis[a + m][a + i],t);
			lasta = a;
		}
	}
	for (re int k = 1;k <= nm;++k){
		for (re int i = 1;i <= nm;++i){
			for (re int j = 1;j <= nm;++j){
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]); 
			}
		}
	}
	int x,y;
	while (q--){
		cin >> x >> y;
		cout << dis[x][y] << '\n';
	}
	return 0;
} 
//不出意外的话能过n*m<=300的数据（所以分值不出意外的话也就12pts啊qnq）
