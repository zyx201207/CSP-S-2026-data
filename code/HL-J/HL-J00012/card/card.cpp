#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, M = 3e5 + 10;
int n, m, a[N], vis[M];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		if(a[i] != a[i + 1]){
			vis[a[i]] = i;
		}
	}
	for(int i = 1; i <= m; i++) cout << vis[i] << ' ';
	return 0;
}
		
                                           