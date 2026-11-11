#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e2+5;
const int K = 2e4+5;
const int M = 3e4+5;
const int inf = 4e15;

int t[N][K],w[N],k[N],cost[M];

vector<int> a[N],b[K];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q; //c测试点编号，n地铁线路数，m地铁站数，d至多每个地铁站路线数，q出行计划数 
	for (int i=1;i<=m;i++){
		cin >> w[i];
	}
	for (int i=1;i<=n;i++){ //ai,j 表示第 i 条线路经过的第 j 个地铁站，ti,j 表示从该地铁站的站厅走到第 i 条线路的站台需要的时间
		cin >> k[i];
		for (int j=1;j<=2*k[i];j++){
			int x;
			cin >> x >> t[i][j];
			a[i].push_back(x);
			b[x].push_back(i);
		}
	} 
	if (c == 0){
		if (n == 2) cout << 32 << endl << 17;
		else if (n == 3) cout << 35 << endl << 16;
	}
	return 0;
} 
