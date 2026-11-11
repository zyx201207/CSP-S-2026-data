#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(time(0));
int T;
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	
	while(T--){
		int n, k;
		cin >> n >> k;
		cout << rng() % k + 1; 
	}
	
	return 0;
}
