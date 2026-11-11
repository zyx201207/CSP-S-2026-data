#include<bits/stdc++.h>
using namespace std;
#define int long long
int const N = 5e5 + 10; 
int n, m, q = 1, t;
int a[N], z[N], js[N];
void mn(int s){
	for(int i = n, j = s; j <= n;i--){
		if(a[i] == a[j]){
			js[a[j]]++;
			j = i + 1;
			i = n + 1; 
		}
	}
}
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i= 1; i <= n; i++){
		mn(i);
	}
	for(int i = 1; i <= m; i++){
		cout << js[i] << " "; 
	}
	return 0;
} 
