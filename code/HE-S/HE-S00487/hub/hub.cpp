#include<bits/stdc++.h>
using namespace std;
int n, k;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1; i <n; i++){
			int u, v;
			cin >> u >> v;
		}
		if(k = n / 2){
			cout << 1 << endl;
		}
		else{
			cout << (n/2+1) / k+1;
		}
	}
	return 0;
}
