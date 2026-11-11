#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int c, T, n, p;
int a[N];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while(T--){
		memset(a, 0, sizeof a);
		cin >> n >> p;
		for(int i = 1; i <= n; i++) cin >> a[i];
		if(p == 1){
			cout << 0 << endl;
			continue;
		}
		
	}
}
