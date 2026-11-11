#include <bits/stdc++.h>
using namespace std;

int c, t, n, k, tmp;

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cin >> c >> t;
	mt19937 rd(745095348);
	while(t--){
		cin >> n >> k;
		for(int i = 1; i < n; i++) cin >> tmp;
		cout << rd() % n << '\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
