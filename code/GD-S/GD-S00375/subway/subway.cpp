#include <bits/stdc++.h>
using namespace std;

queue<pair<int,int> > q;
int x,y;
int k[501000];
int t[510][500100];
int gi[510100];
vector <int> e[500100];
bool f[10000][10000];


void bfs(int x,int y){
	for (int i = 0;i < e[x].size();i++){
		if(f[x][e[x][i]] != 1||){
			q.push({x,e[x][i]});
			
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	cin >> c >> n >> m >> d >> p;
	int u,v;
	for (int i = 1;i <= m;i++){
		cin >> gi[i];
	}
	for (int i = 1;i <= n;i++){
		cin >> k[i];
		for (int j = 1;j <= k[i];j++){
			cin >> u >> t[i][j];
			if(j != 1){
				e[u].push_back(v);
				e[v].push_back(u);
			}v=u;
		}
	}
	long long ans = LLONG_MAX;
	int add = 0;
	while(p--){
		cin >> x >> y;
//		ans
		add = gi[x]+gi[y];
		for (int i = 1;i <= 10000;i++){
			f[x][i] = 0;
			f[i][x] = 0;
		}q.push({0,x});
		bfs(x,0);
	}
	return 0;
} 
