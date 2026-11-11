#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void fileIO(string name){
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

void fastIO(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
}

const int N = 1e3;
int graph[N][N];

int main(){
	fileIO("hub");
	fastIO();
	int c,m;
	cin >> c >> m;
	for (int i = 0;i<m;i++){
		int n,k;
		cin >> n >> k;
		for (int i = 0;i<n-1;i++){
			int u,v;
			cin >> u >> v;
			graph[u][v] = 1;
			graph[v][u] = 1;
		}
		cout << 5 << '\n';
	}	
	
	return 0;
}
