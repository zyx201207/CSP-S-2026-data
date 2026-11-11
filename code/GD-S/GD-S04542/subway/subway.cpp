#include <bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define ll long long
#define pll pair<int, ll>
const int N = 5e5 + 7;
int testcase;
int n, m, maxgoing;
vector<pll> jingguo[N];
ll f[507][507], w[N];
int Q;
void makeMin(ll &a, ll b) {
	a = min(a, b);
}
void init() {
	cin >> testcase;
	cin >> n;
	cin >> m;
	cin >> maxgoing;
	cin >> Q;
	rep(i, 1, m){
		cin >> w[i];
	}
}
void makeGraph() {
	rep(i, 1, n) {
		int k;
		cin >> k;
		while(k -- ) {
			int x; ll w;
			cin >> x >> w;
			jingguo[x].push_back({i, w});
		}
	}
	rep(i, 1, n) {
		rep(j, 1, n) {
			if(i != j) f[i][j] = 1e15;
		}
	}
	rep(i, 1, m) {
		//记录经过地铁站i的铁路之间的转换 
		for (pll w1 : jingguo[i]) {
			for(pll w2 : jingguo[i]) {
				makeMin(f[w1.first][w2.first], w1.second + w2.second);
			}
		}
	}
}
void runFloyd() {
	rep(k, 1, n) {
		rep(i, 1, n) {
			rep(j, 1, n) {
				makeMin(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
}
void answerQueries() {
	while(Q--) {
		int x, y;
		cin >> x >> y;
		ll answer = 1e16;
		for(pll w1 : jingguo[x]) {
			for(pll w2 : jingguo[y]) {
				makeMin(answer, w1.second + w2.second + f[w1.first][w2.first]);
			}
		}
		cout << w[x] + w[y] + answer << "\n";
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	init();
//	读入量参数 
	
	makeGraph();
//	用经过同一换乘站的地铁线之间的关系来建图 

	runFloyd();
//	把【相邻(可换乘)两地铁线距离】扩展为【任意两地铁线距离】 

	answerQueries();
//	真刀真枪，用【两地铁线的距离】实际回答问题 
	return 0;
}

//EG1
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
//(32 17)

//EG2
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3
//(35 16)

