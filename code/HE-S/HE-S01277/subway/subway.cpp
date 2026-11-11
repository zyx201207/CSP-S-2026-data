#include<bits/stdc++.h>
#define int long long 

using namespace std;

const int N = 5e5 + 10;
const int M = 1010;
const int mod = 998244353;
const double eps = 1e-9;
typedef long long LL;
typedef unsigned long long ULL;
typedef double db;
typedef pair<int, int> PII;
//bool START;

int _, m, n, d, T;
int w[N], k[N];

vector<PII> p[N]; // p[i] 表示能到达这个点的所有 {路线编号，走路步数} 
int f[M][M]; // f[i][j] 表示从路线 i 到路线 j 的最小步数 

void floyd(){
	for(int i = 1 ; i <= m ; i ++){
		for(int j = 1 ; j <= m ; j ++){
			for(int k = 1 ; k <= m ; k ++){
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
}

//bool END;
signed main(){
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin>>_>>m>>n>>d>>T;
	
	for(int i = 1 ; i <= n ; i ++){
		cin>>w[i];
	}
	
	memset(f, 0x3f, sizeof f);
	
	for(int i = 1 ; i <= m ; i ++){
		f[i][i] = 0;
		cin>>k[i];
		for(int w = 1 ; w <= k[i] ; w ++){
			int a, t;
			cin>>a>>t;
			
			for(auto path : p[a]){
				int j = path.first, dt = path.second;
				f[i][j] = min(f[i][j], t + dt);
				f[j][i] = min(f[j][i], t + dt);
			} 
			p[a].push_back({i, t});
		}
	}
	
	floyd();
	
	for(int i = 1 ; i <= T ; i ++){
		int x, y;
		cin>>x>>y;
		
		if(x == y){
			cout<<0<<'\n';
			continue;
		}
		
		int ans = 0x3f3f3f3f3f3f3f3f;
		for(auto px : p[x]){
			for(auto py : p[y]){
				ans = min(ans, px.second + f[px.first][py.first] + py.second);
			}
		}
		cout<<w[x] + ans + w[y]<<'\n';
	}
	
//	cerr<<"Memory : "<<abs(&END - &START) / 1024.0 / 1024.0<<'\n';
	return 0;
}
