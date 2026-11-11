#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int n, m, ans[300005];
int a[200005];
bool f[200005][3005];
int last[3005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = n; i >= 1; i--) {
		int pos;
		f[i][a[i]] = 1;
		if(last[a[i]] == 0) {
			pos = 1;
		} else {
			pos = abs(i - last[a[i]]);
		}
		for(int j = 1; j <= m; j++) {
			if(j != a[i]) {
				f[i][j] = f[i + pos][j];	
			}
			if(f[i][j] == 1) {
				ans[j]++;
			}
		}
		last[a[i]] = i;
	} 
	for(int i = 1; i <= m; i++) {
		cout << ans[i] <<' ';
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
