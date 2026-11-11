#include <iostream>
//#include <fstream>
#include <vector>
using namespace std;

int c, n, m, d, q;
vector<int> t[510];
//vector<int> a[510];
vector<int> deg[500010];
int pos[510][500010];//line i, id=j, where it is in the line.
int w[500010];

inline long long W(int i1, int j1, int i2, int j2) {
	//if(a[i1][j1]!=a[i2][j2]) return 1e18;
	return t[i1][j1]+t[i2][j2];
}
long long f[510][510];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	//ofstream logger("subway.log");
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//auto st=time(0);
	
	cin>>c>>n>>m>>d>>q;
	
	//logger<<n<<' '<<m<<endl;
	
	for(int i=1;i<=m;++i) cin>>w[i];
	int k, _a, _t;
	for(int i=1;i<=n;++i) {
		cin>>k;
		t[i].resize(k+1);
		//a[i].resize(k+1);
		//pos[i].resize(m+1);
		for(int j=1;j<=k;++j) {
			cin>>_a>>_t;
			t[i][j]=_t;
			//a[i][j]=_a;
			deg[_a].push_back(i);
			pos[i][_a]=j;
		}
	}
	
	//logger<<time(0)-st;
	
	for(int i=0;i<=n+2;++i) for(int j=0;j<=n+2;++j) f[i][j]=1e18;
	
	for(int i=1;i<=m;++i) {
		if(deg[i].size()>1) {
			for(int u:deg[i]) {
				for(int v:deg[i]) {
					f[u][v]=min(f[u][v], W(u, pos[u][i], v, pos[v][i]));
				}
			}
		}
	}
	for(int i=1;i<=n;++i) f[i][i]=0;
	
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			for(int k=1;k<=n;++k) {
				f[i][j]=min(f[i][j], f[i][k]+f[k][j]);
			}
		}
	}
	
	/*
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			cout<<f[i][j]<<' ';
		}
		cout<<"\n";
	}*/
	
	int x, y;
	for(int i=1;i<=q;++i) {
		cin>>x>>y;
		long long ans=1e18;
		for(int u:deg[x]) {
			for(int v:deg[y]) {
				//cout<<u<<' '<<v<<' '<<pos[u][x]<<' '<<pos[v][y]<<endl;
				ans=min(ans, f[u][v] + t[u][pos[u][x]] + t[v][pos[v][y]]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
