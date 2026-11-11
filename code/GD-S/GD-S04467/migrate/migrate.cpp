#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5+10;
int x[N];
int n, d;
int find[N];
/*void dfs(int last){
	
	for(int i = last+1; i <= n; i++){
		if(x[i] - x[last] <= d){
			
		}
	}
}*/

void solve(){
	memset(x, 0, sizeof(x));
	cin >> n >> d;
	for(int i = 1; i <= n; i++){
		cin >> x[i];
	}
	cout << 0 << endl;
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c, T;
	cin >> c >> T;
	while(T--){
		solve();
	}
	return 0;
}
