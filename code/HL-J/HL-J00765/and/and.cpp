#include <bits/stdc++.h>

using namespace std;

int n , a[2000100] , m , ma;

int main (){

	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	
	cin >> n >> m;
	
	for (int i = 1  ; i <= n ; i++){
		cin >> a[i];
	}
	
	sort (a + 1 , a + n + 1);
	
	reverse(a + 1 , a + n + 1);
	
	ma = a[1];
	
	for (int i = 1 ; i <= m ; i++){
		ma = a[i] & ma;
	}
	
	cout << ma;

	return 0;
}
