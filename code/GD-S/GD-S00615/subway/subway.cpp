#include <bits/stdc++.h>
using namespace std;
long long w[500010];
vector<long long> e[510];
vector<long long> t[510];
int k[510];
int c, n, m, d, q;

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			int ai, ti;
			cin >> ai >> ti;
			e[i].push_back(ai);
			t[i].push_back(ti);
		}
	}
	for(int i = 1;i <= r;i++){
		int x, y;
		cin >> x >> y;
	}
	
	return 0;
}
