#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 5e2+10;
const int M = 5e5+10;
const int Q = 1e5+10;
int c, n, m, d, q;
int a[N][M], t[N][M], w[M];
pii qu[Q];
vector<pii>a[M];
struct DSU{
	int fa[M], sz[M];
	void init(int n){
		iota(fa+1,fa+1+n,0);
	}
	int find(int x){
		if(fa[x]==x) return x;
		return fa[x] = find(fa[x]);
	}
	bool merge(int x, int y){
		int xx = find(x);
		int yy = find(y);
		if(xx==yy) return 0;
		
	}
};
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <=m;i++){
		cin >> w[i];
	}
	bool k = 1;
	int T = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i][0];
		for(int j = 1;j <= a[i][0];j++){
			cin >> a[i][j];
			cin >> t[i][j];
			if(i==1&&j==1) T = t[i][j];
			if(T!=t[i][j]) k = 0;
		}
	}
	for(int i = 1;i <= q;i++){
		cin >> qu[i].first >> qu[i].second;
	}
	if(k){
		for(int i = 1;i <= q;i++){
			int wi = 0, cnt = 0;
			queue<int>p;
			auto [p1,p2] = qu[i];
			p.push(p1);
			wi+=w[i];
			while(!p.empty()){
				int pp = p.front();
				p.pop();
				for()
			}
		}
	}
	return 0;
}

