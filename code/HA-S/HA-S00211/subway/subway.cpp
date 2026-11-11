#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 600;
int c, m, n, d, q;
int cost[N];
int dis[N][N], idx;

int k[N];
vector<int> e[N];
set<int> ge;
int totscc;
int low[N],dfn[N];
inline void tarjan(int x){
	dfn[x] = low[x] = ++idx;
	for(const auto o : e[x]){
		int tree = 0;
		if(!dfn[o]){
			tarjan(o);
			low[x] = min(low[x], low[o]);
		}
		else{
			if(low[o] < dfn[x] || ++tree>2){
				ge.insert(x);
				totscc++;
			}
			low[x] = min(low[x],dfn[o]);
		}
	}
}
main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;++i){
		cin>>cost[i];
	}
	
	memset(dis,0x3f,sizeof dis);
	for(int i = 1;i<=n;++i){
		cin >> k[i];
		for(int j = 1; j<=k[i];++j){
			int tmp;
			cin>>tmp;
			cin>>dis[i][tmp];
		}     
	}  
		for(int i = 1;i<=m;++i){
			for(int j = 1;j<=m;++j){
				if(dis[i][j] != 0x3f3f3f3f3f3f3f3f && i != j){
					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
		}
			for(int i = 1;i<=m;++i){
		for(int j = 1;j<=m;++j){
			cout<<dis[i][j]<<' ';
		}
		cout<<endl;
	}
	for(int i = 1;i<=m;++i){
		if(!dfn[i]){
			tarjan(i);
		}
	}
	for(int i = 1;i<=m;++i){
		for(int j = 1;j <= m; ++j){
			dis[j][i] = dis[i][j];
		}
	}
	
	for(int j = 1; j <= m;++j){
		for(int i = 1;i<=m;++i){
			for(int k1 = 1;k1<=m;++k1){
						dis[i][k1] = min(dis[i][k1],dis[i][j]+dis[j][k1]);
					}
				}
			}

	for(int i = 1;i<=q;++i){
		int l,r;
		cin>>l>>r;
		int ans =cost[l]+cost[r]+dis[l][r];
		for(const auto o : ge){
					if(l < o&& r>o){
						ans+=dis[o][o];
					}
				}
				cout<<ans<<endl;
}}