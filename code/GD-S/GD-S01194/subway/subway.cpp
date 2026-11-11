#include<bits/stdc++.h>
#define endl '\n' 
#define ll long long
using namespace std;
const int N=501;
const int M=401;

int c,n,m,d,q;

int w[M]; // i号站点  口 到 厅 距离 
int x[M],y[M];

int a[N][M]; // i线路经过的站点 
vector<int>g[N]; // i点 可换乘的线 
int t[N][M]; // i号线路 在j站点  线台 到 站厅 距离 


void solve1() {
	for(int i=1;i<=q;i++) {
		cout<<i<<endl;
		//dfs
		// fuck ccf
	}
	return;
}

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) {
		cin>>w[i];
	}
	for(int i=1;i<=n;i++) { // 线i 
		int k; cin>>k;
		for(int j=1;j<=k;j++) { // i过的点 
			cin>>a[i][j]>>t[i][j];
			g[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=q;i++) {
		cin>>x[i]>>y[i];
	}
	if(c <= 8) {
		solve1();
	}
	return 0;
}
