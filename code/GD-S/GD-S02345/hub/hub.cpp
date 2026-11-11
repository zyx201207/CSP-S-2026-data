#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5, M = 5e3 + 5;
int c, t;
vector<int> p[N];

void solve(){
	int n, k;
	cin >> n >> k;
	for(int i = 1;i <= n - 1;i++){
		int u, v;
		cin >> u >> v;
		p[u].push_back(v);
		p[v].push_back(u); 
	}
} 

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--) solve();
	return 0;
}

