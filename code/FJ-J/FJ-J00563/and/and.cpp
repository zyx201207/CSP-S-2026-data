#include<bits/stdc++.h>
using namespace std;
int a[200005];
int v[200005];
int n, m;
int mx = 0;
void dfs(int k, int sum){
	if(k == m){
		mx = max(sum, mx);
		return ;	
	}
	for(int i = 1; i <= n; i++){
		if(v[i] == 0){
			v[i] = 1;
			if(k == 0){
				dfs(k+1, a[i]);
			}else{
				dfs(k+1, sum&a[i]);
			}
			v[i] = 0;
		}
	}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	bool f = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != i-1){
			f = 0;
		}
	}
	if(m == 1){
		sort(a+1, a+n+1);
		cout << a[n] << endl;
		return 0;
	}
	if(n <= 2000&&m<= 20){
		dfs(0, 0);
		cout << mx << endl;
		return 0;
	}
	if(m == n){
		int s = a[1];
		for(int i = 2; i <= n; i++){
			s &= a[i];
		}
		cout << s;
		return 0;
	}
	if(m == (n-1)){
		for(int i = 1; i <= n; i++){
			if(i == 1){
				int s = a[2];
				for(int j = 3; j <= n; j++){
					s &= a[j];
				}
			}else{
				int s = a[1];
				for(int j = 2; j <= n; j++){
					if(j != i){
						s &= a[j];
					}
				}
			}
		}
		return 0;
	}
	sort(a+1, a+n+1);
	cout << a[n-m+1];
	return 0;
}
