#include <bits/stdc++.h> 
#define int long long
using namespace std;
int n , m;
const int maxn = 4e5 + 10;
int a[maxn] , b[maxn] , c[maxn];
signed main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		b[a[i]] = i;
	}
	for(int i = 1 ; i <= n ; i++){
		int j = i;
		int max1 = 0;
		while(j <= n){
			c[a[j]]++;
			max1 = b[a[j]];
			j = max1 + 1;
		}
		for(int x = max1 + 1 ; x <= n ; x++){
			c[a[x]]++;
		}
	}
	for(int i = 1 ; i <= m ; i++){
		cout << c[i] << ' ';
	}
	return 0;
}
