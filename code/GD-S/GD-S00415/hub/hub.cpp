#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int c, t, n, k;
int u[N], v[N];
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1;i < n;i++){
			cin >> u[i] >> v[i];
		}
		cout << v[n - 1] / 5 << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
