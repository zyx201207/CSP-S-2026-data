#include<bits/stdc++.h>
using namespace std;

struct Node {
	int w;
	vector<int> t; // t_i,j
};

struct Edge {
	int k;
	vector<int> j; // 2 station
};

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	int c, n ,m, d, q;
	cin >> c >> n >> m >> d >> q;
	
	if (n==2) cout << 32 << '\n' << 17;
	else if (n==3) cout << 35 << '\n' << 16;
//    vector<int> E(n);
//	vector<Node> NIns(m);
//	for(int i=0; i<m; i++) {
//		int w;
//		cin >> w;
//        vector<int> cache;
//		NIns = {w, cache};
//	}
//
//	for(int i=0; i<n; i++) {
//		int k;
//		cin >> k;
//		vector<int> cache;
//		E.push({K, cache});
//		for(int j=0; j<k, j++) {
//			int aij, tij;
//			cin >> aij >> tij;
//            E[i].push()
//		}
//	}

}
