#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200010];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(m == 1){
		cout << 0;
		return 0;
	}else if(m == n){
		cout << 0;
		return 0;
	}
	return 0;
}
