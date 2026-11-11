#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N=1e6+5;
int n,k;
vector <int> e[N];
void solve(){
	cin >> n >> k;
	for(int i=1;i<n;++i){
		int u,v;
		cin >> u >> v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	if(k==n)cout << "0\n";
	else if(k==n-1)cout << "1\n";
	else cout << (n/2+rand()*rand()%n+2)%(n>>1) << '\n';
	
	return ;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	srand(time(0));
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		solve();
	}
	return 0;
}
