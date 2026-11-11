#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
char c , cc[N];
long long a , sum , cnt = 1 , ans , aa[N];
char f(int k){
	for(int i = 1; i <= n; i++){
		if(aa[i] >= k) return cc[i];
	}
}
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a >> c;
		cc[i] = c;
		sum += a;
		aa[i] = sum;
	}
	int l = sum / 2 , r = sum / 2 + 1;
	if(sum % 2 == 1) r++;
	while(l >= 1 && r <= sum){
		char p = f(l) , q = f(r);
		if(p != q) ans++;
		l-- , r++;
	}
	cout << ans;
	return 0;
}
