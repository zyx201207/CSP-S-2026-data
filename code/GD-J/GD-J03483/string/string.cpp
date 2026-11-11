#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
int a[N];
char c[N * 500];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n, x = 1, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		char ch;
		cin >> a[i] >> ch;
		for(int j = 1; j <= a[i]; j++, x++){
			c[x] = ch;
		}
	}
	x--;
	for(int i = 1, j = x; i <= x / 2;i++, j--){
		if(c[i] != c[j]){
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}
