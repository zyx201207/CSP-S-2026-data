#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int a[N];
int b[N];
bool vis[N];
int n, m;
void work(int l, int r){
	memset(vis, 0, sizeof vis);
	for(int i = l; i <= r; i++){
//		cout << "##" << i << '\n';
		int k = r + 1;
//		cout << k << '\n';
		for(int j = i - 1; j >= l; j--){
//			cout << a[j] << ' ';
			if(a[j] == a[i] && vis[j] == 0){
				k = j;
				break;
			}
		}
//		cout << '\n';
//		cout << k << '\n';
		for(int j = k; j <= i - 1; j++){
			vis[j] = 1;
		}
//		for(int i = 1; i <= n; i++){
//			cout << vis[i] << ' ';
//		}
//		cout << '\n';
	}
	for(int i = l; i <= r; i++){
		if(vis[i] == 0){
//			cout << i << ' ' << a[i] << '\n';
			b[a[i]]++;
		}
	}
//	cout << "\n\n";
}
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		work(i, n);
//		for(int i = 1; i <= m; i++){
//			cout << b[i] << ' ';
//		}
//		cout << '\n';
	}
	for(int i = 1; i <= m; i++){
		cout << b[i] << ' ';
	}
} 
/*
4 3
1 2 1 3

*/
