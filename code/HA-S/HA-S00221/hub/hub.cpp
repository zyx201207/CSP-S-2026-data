#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int c, t;
int n, k;
int u[N], v[N];

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		int minx = INT_MAX;
		for (int i = 1; i <= n; i++){
			cin >> u[i] >> v[i];
			minx = min(minx, abs(v[i] - u[i]));
		}
		cout << minx << endl;
	}
}