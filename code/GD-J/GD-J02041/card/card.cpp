/*
	love zxy
	da gai shi wo bi jiao nuo ruo ba
	zhi gan zai zhi li shuo xi huan ni
*/

#include<bits/stdc++.h>
using namespace std;

int n, m; 
int t[500005];
int a[500005];
bool c[300005];
int cnt[300005];

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		a[i] = t[i];
	}
		
	for (int i = 1; i <= n; i++) {
		
		for (int j = i; j <= n; j++) {
			if (c[a[j]] == 1) {
				for (int x = j-1; x >= 1; x--) {
					if (a[x] == a[j]) {
						a[x] = -1;
						break;
					}
					else 
						a[x] = -1;
				}
			}
			else 
				c[a[j]] = 1;
		}
		
		// tong ji
		for (int j = i; j <= n; j++)
			if (a[j] != -1)
				cnt[a[j]]++;
		
		// chu shi hua
		for (int x = 1; x <= m; x++) 
			c[x] = 0;
		
		for (int x = i; x <= n; x++)
			a[x] = t[x];
	}
	
	for (int i = 1; i <= m; i++)
		cout << cnt[i] << ' ';
	return 0;
}

