#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m; cin >> n >> m;
	vector<int> a(n);
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		
	}
	for(int j = 1; j <= m; j++){
		for(int i = 1; i <= n; i++)if(a[i] > cnt)cnt = a[i];
		for(int i = 1; i <= n; i++) if(a[i] == cnt)a[i] = 0;
		if(j == m){
			cout << cnt;
			return 0;
		}
		cnt = 0;
	}
	cout << cnt;
	return 0;
}
