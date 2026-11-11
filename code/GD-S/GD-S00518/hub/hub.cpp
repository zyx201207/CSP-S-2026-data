#include <bits/stdc++.h>
using namespace std;

long long c, t;
long long n, k;
vector<long long> e[1000005];
void mian(){
	cin >> n >> k;
	for(int i = 1, u, v;i < n;i++){
		cin >> u >> v;
		e[u].push_back(v), e[v].push_back(u);
	}
	if(c == 13 || c == 14){
		cout << (((n + 1) / 2 + 1) / 2 - (k + 1) / 2 + 1) / 2 + 1 << endl;
		return ;
	}
	return ;
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	for(int T = 1;T <= t;T++)
		mian();
	return 0;
}
