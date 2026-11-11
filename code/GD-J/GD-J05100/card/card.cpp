#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+10;
ll n, m;
ll a[N], table[N], b[N];
int main (){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			for (int k = 1; i <= j; k++){
				if (table[k] == a[j] || table[k-1] == 0)
					table[k] = 0;
			}	
			table[j] = a[j];
			a[j] = 0;
		}
		for (int j  = i; j <= n; j++){
			if (table[j]) b[table[j]]++;
		}
	}
	for (int i = 1; i <= m; i++) cout << b[i] << ' ';
	return 0;
}
