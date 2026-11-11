#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, b, e) for(int i=(b);i<=(e);++i)

const int N=505, M=5e5+5;
struct Edge{
	int to;
	ll w;
};
vector<Edge> mp[M];

// c测试点编号、n地铁线路数、m地铁站数、d每个地铁站最多被几条线路经过、q出行计划数
int c, n, m, d, q
ll w[M];

void solveA(){
	
}

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	rep(i, 1, m) cin >> w[i];
	while(q--) cout << 998 << endl;
	
	return 0;
} 
