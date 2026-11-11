#include <bits/stdc++.h>
#define ll long long

using namespace std;

int a[500005], b[500005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	map<int, int> mp;
	for(int i = 1; i <= n; i++) {
		map<int, int> mp1; 
		for(int j = 0; j <= n; j++) b[j] = 0;
		for(int j = i; j <= n; j++) {
			if(mp1[a[j]]) {
				b[mp1[a[j]]] += 1;
				b[j] -= 1;
				for(int k = mp1[a[j]]; k < j; k++) mp1[a[k]] = 0;
				mp1[a[j]] = j;
			}
			else mp1[a[j]] = j;
		}
		for(int j = i; j <= n; j++) {
			b[j] = b[j - 1] + b[j];
			if(b[j] == 0) mp[a[j]]++;
		}
	}
	for(int i = 1; i <= m; i++) cout << mp[i] << ' ';

	return 0; 
} 
