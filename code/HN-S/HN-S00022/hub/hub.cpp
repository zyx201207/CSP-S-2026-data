#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int CCF;
int n, m;
vector<int> adj[N];

void Solve(){
	cin >> n >> m;
	for(int i = 1, u, v; i <= m; i++){
		cin >> u >> v;
	}
	if(!m) cout << n << '\n';
	else if(m == n) cout << "0\n";
	else{
		int num = n / 2;
		if(m >= num) cout << "1\n";
		else cout << (num - m + 3) / 4 + 1;
	}
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	cin >> CCF >> T;
	while(T--) Solve();
	return 0;
}
/*

*/
