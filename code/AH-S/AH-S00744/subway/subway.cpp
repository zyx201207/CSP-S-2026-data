#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
vector<int> w(m+1);
struct Node{
	int a;
	int t;
}
Node subway[505][505];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i<=n; i++){
		int k;
		cin >> k
		for (int j = 1; j<=k; j++){
			cin >> subway[i][j].a >> subway[i][j].t;
		}
	}
	while (q--){
		int x, y;
		cin >> x >> y;
		
	}
	
}
