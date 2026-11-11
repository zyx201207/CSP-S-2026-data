#include <iostream>
using namespace std;
const int MAXN = 2 * 1e5 + 5;
int a[MAXN];
char c[MAXN];
long long ans;
int n;
int main(){
//	freopen("string.in" , "r" , stdin);
//	freopen("string.out" , "w" , stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i] >> c[i];
	}
	int L = 1 , R = n;
	while(L < R){
		int t1 = a[L] , t2 = a[R];
		if(c[L] != c[R]){
			ans += min(t1 , t2);
		}
		a[L] -= min(t1 , t2);
		a[R] -= min(t1 , t2);
		if(a[L] == 0) L++;
		if(a[R] == 0) R--;
	}
	cout << ans;
	return 0;
} 
