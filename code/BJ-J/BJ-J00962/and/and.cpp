#include<bits/stdc++.h>
using namespace std;
int n, m, a[2005];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(m == 1){
		int maxx = -10086;
		for(int i = 1; i <= n; i++){
			maxx = max(maxx, a[i]);
		}
		cout << maxx;
		return 0;
	}
	if(m == n){
		int qwq = a[1] & a[2];
		for(int i = 3; i <= n; i++){
			qwq &= a[i]; 
		}
		cout << qwq;
		return 0;
	}
	int maax = -114514;
	for(int i = 1; i <= n; i++){
		for(int TT = i + 1; TT <= n; TT++){
			maax = max(maax, a[i] & a[TT]);
		}
	}
	cout  << maax;
	return 0;
} 
