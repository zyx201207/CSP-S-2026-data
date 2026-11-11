//GZ-J00304 遵义市播州区南白初级中学 王耀葵  
#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ ){
		cin >> a[i];
	}
	int mx = 0;
	for(int i = 1; i <= n; i ++ ){
		for(int j = i + 1; j <= n; j ++ ){
			mx = max(mx, a[i] & a[j]);
		}
	}
	cout << mx;
	return 0;
}
