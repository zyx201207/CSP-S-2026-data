#include <bits/stdc++.h>
using namespace std;
int a[100006];
int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	for(int i = 0;i <= n;i++){
		cin >> a[i];
	}
	sort(a, a + n + 1);
	cout << a[n/2 + 1];
	return 0;
}
