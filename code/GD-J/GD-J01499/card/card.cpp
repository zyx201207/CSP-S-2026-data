#include<bits/stdc++.h>

using namespace std;

const int maxn = 5000005;
const int maxm = 3000005;

int n, m;
int a[maxn], arr[maxn], cnt[maxm], last[maxm];

void solve(int start, int a[], int l[]) {
	for(int i = start; i < n; i++) {
		int v = a[i];
		if(v != 0) {
			if(l[v] != i) {
				for(int j = i; j < l[v]; j++) a[j] = 0;
				i = l[v];
			}
			cnt[v]++;
		}
	}
} 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		last[a[i]] = i;
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) arr[j] = a[j];
		solve(i, arr, last);
	}
	
	for(int i = 1; i <= m; i++) {
		cout << cnt[i] << ' ';
	}
	
	return 0;
}
