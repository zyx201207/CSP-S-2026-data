#include<bits/stdc++.h>
using namespace std;
#define N 500007
int n, m;
int a[N];
int c[N];
int d[N];
int s[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >>m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			d[j] = 0;
		} 
		for(int j = i; j <= n; j++) {
			c[j] = a[j];
			if(d[c[j]]) {
				for(int k = d[c[j]]; k < j; k++) {
					d[c[k]] = 0, c[k] = 0;
				}
			}
			d[c[j]] = j;
		}
		for(int j = i; j <= n; j++) {
			if(c[j]) s[c[j]]++;
		}
	}
	for(int i = 1; i <= m; i++) {
		cout << s[i] << " ";
	}
	return 0;
} 
