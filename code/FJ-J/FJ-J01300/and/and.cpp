#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
	return a > b;
} 
int main(){
	freopen("and.in", r, stdin);
	freopen("and.out", w, stdout);
	int n, m;
	int a[200005] = {0};
	cin >> n >> m;
	bool b = (m == 1) ;
	bool b1 = (m == 2) ;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a, a+n, cmp);
	if(!b){
		long long ans = a[0];
		for(int i = 1; i < m; ++i){
			ans = ans & a[i];
		}
		cout << ans;
	}else if(b1){
		cout << a[0] & a[1];
	}else{
		cout << a[0];
	}
	return 0;
} 
