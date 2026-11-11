#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], d[N], last[N], t[N], cnt = 0;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	
	for(int i = 1; i <= n; ++i) {
		int l = 1, r = 0;
		memset(last, 0, sizeof(last));
		for(int j = i; j <= n; ++j) {
			if(last[a[j]] != 0 && d[last[a[j]]] == a[j] && last[a[j]] <= r) {
				r = last[a[j]];
			}
			else {
				d[++r] = a[j];
				last[a[j]] = r;
			}
		}
		
		for(int j = 1; j <= r; ++j) {
			t[d[j]]++;
		}
	}
	
	for(int i = 1; i <= m; ++i) {
		cout << t[i] << ' ';
	}
}
