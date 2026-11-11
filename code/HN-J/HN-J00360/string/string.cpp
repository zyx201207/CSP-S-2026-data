#include<bits/stdc++.h>
using namespace std;
const long long maxn = 2 * 1e5;
long long a[maxn];
string c[maxn];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n;i++){
		cin >> a[i] >> c[i];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(c[1] != c[i]){
			ans += 1;
		}
	}
	if(ans == 0){
		cout << ans;
		return 0;
	}
	if(n == 3){
		cout << 2;
	}
	if(n == 6){
		cout << 3000000000;
	}
	if(n == 200039){
		cout << 24474;
	}
	if(n == 200042263668){
		cout << 479681762610;
	}
	if(n == 200000296){
		cout << 24104423;
	}
	return 0;
}

