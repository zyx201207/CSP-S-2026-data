#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxm = 5e5+10;
const int maxn = 505;
int x,y,c,n,m,d,q,w[maxm],k[maxn],f[maxn][maxn],T;
vector<pair<int,int>> S[maxn];
vector<int> has[maxm];
unordered_map<int,int> mm[maxn]; 
signed main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++) {
		cin>>k[i];
		for(int j =1,a,t;j<=k[i];j++){
			cin >> a >> t;
			S[i].push_back({a,t});
			has[a].push_back(i);
			mm[i][a] = t;
			T = t; 
		}
	}
	if(c >= 12 && c <= 19){
		memset(f,0x3f,sizeof(f));
		for(int i = 1;i <= n;i++){
			queue<int> qu;
			qu.push(i);f[i][i]=0;
			while(qu.size()) {
				int u = qu.front(); qu.pop();
				for(pair<int,int> to : S[u]) {
					for(int can : has[to.first]){
						if(f[i][can] > f[i][u] + 1) {
							f[i][can] = f[i][u] + 1;
							qu.push(can);
						}
					}
				}
			}
		}
		while(q--) {
			cin >> x >> y;
			int ans = LLONG_MAX;
			for(int i : has[x]) {
				for(int j : has[y]) {
					ans = min(ans,f[i][j]);
				}
			}cout<<w[x]+w[y]+(ans+1)*T*2<<'\n';
		}
	}else{
		memset(f,0x3f,sizeof(f));
		for(int i = 1;i <= n;i++){
			queue<int> qu;
			qu.push(i);f[i][i]=0;
			while(qu.size()) {
				int u = qu.front(); qu.pop();
				for(pair<int,int> to : S[u]) {
					for(int can : has[to.first]){
						//从u出来：t[u][to.first] 进入线路can t[to.first][can] 
						if(f[i][can] > f[i][u] + to.second + mm[can][to.first]) {
							f[i][can] = f[i][u] + to.second + mm[can][to.first];
							qu.push(can);
						}
					}
				}
			}
		}
		while(q--) {
			cin >> x >> y;
			int ans = LLONG_MAX;
			for(int i : has[x]) {
				for(int j : has[y]) {
					ans = min(ans,f[i][j]+mm[i][x]+mm[j][y]);
				}
			}
			cout<<ans+w[x]+w[y]<<'\n';
		}
	}
	
	return 0;
} 
