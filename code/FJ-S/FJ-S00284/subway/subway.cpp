#include<bits/stdc++.h>
using namespace std;

const int N=5e5+7, M=5e2+7;

int c, n, m, d, q;
long long w[N];
long long st[M][M];
vector<pair<int, long long>> lines[N];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &m, &n, &d, &q);
	for(int i=1;i<=n;i++){
		scanf("%lld", w+i);
	}
	for(int i=1;i<=m;i++){
		int ki;
		scanf("%d", &ki);
		for(int j=1;j<=ki;j++){
			int x;
			long long y;
			scanf("%d%lld", &x, &y);
			lines[x].push_back({i, y});
		}
	}
	memset(st, -1, sizeof(st));
	for(int i=1;i<=n;i++){
		for(auto e : lines[i]){
			for(auto f : lines[i]){
				if(e.first!=f.first){
					if(st[e.first][f.first]==-1 || st[e.first][f.first]>e.second+f.second){
						st[e.first][f.first] = e.second+f.second;
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		st[i][i] = 0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				if(st[i][j]==-1 && st[i][k]!=-1 && st[k][j]!=-1){
					st[i][j] = st[i][k]+st[k][j];
				}else
				if(st[i][j]>st[i][k]+st[k][j] && st[i][k]!=-1 && st[k][j]!=-1){
					st[i][j] = st[i][k]+st[k][j];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x, y;
		scanf("%d%d", &x, &y);
		long long res = LONG_LONG_MAX;
		for(auto e : lines[x]){
			for(auto f : lines[y]){
				res = min(st[e.first][f.first]+e.second+f.second+w[x]+w[y], res);
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}
