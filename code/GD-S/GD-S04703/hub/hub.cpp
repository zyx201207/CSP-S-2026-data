#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 10;
const ll INF = 1e18;
const int mod = 1e9 + 7;
#define pii pair<ll , ll>

int c , t , n , k;
vector<int> e[N];

int main(){
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1 , u , v ; i < n ; i++){
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int m = (n - 1) / 2;
		int ans = m + 1;
		if(k == 1) ans = (ans + 1) / 2;
		else ans = (ans + 2) / 3;
		cout << ans << '\n';
	}
	return 0;
} 


/*
FC /W D:\GD-S04703\subway\subway.ans D:\GD-S04703\subway\subway.out




*/
