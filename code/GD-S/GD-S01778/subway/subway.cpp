#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Node{
	int v,w;
};
int c,n,m,d,q,W[500006],cnt,u,v,w,f[506][506];
vector<Node> g[500006];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m; i++)
		cin >> W[i];
	for(int o = 1;o <= n; o++){
		cin >> cnt;
		for(int i = 1;i <= cnt; i++){
			cin >> u >> w;
			g[u].push_back({o,w});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i = 1;i <= m; i++){
		for(Node p1:g[i])
			for(Node p2:g[i]){
				int v1 = p1.v,w1 = p1.w,v2 = p2.v,w2 = p2.w;
				if(v1 == v2) continue;
				f[v1][v2] = min(f[v1][v2],w1+w2);
			}
	}
	for(int i = 1;i <= n; i++)
		f[i][i] = 0;
	for(int k = 1;k <= n; k++)
		for(int i = 1;i <= n; i++)
			for(int j = 1;j <= n; j++)
				f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
	for(int i = 1;i <= q; i++){
		cin >> u >> v;
		int Ans = 1e18;
		for(Node p1:g[u])
			for(Node p2:g[v]){
				int v1 = p1.v,v2 = p2.v,w1 = p1.w,w2 = p2.w;
				Ans = min(Ans,f[v1][v2]+W[u]+W[v]+w1+w2);
			}
		cout << Ans << endl;
	}
	return 0;
}
