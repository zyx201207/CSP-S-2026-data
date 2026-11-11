#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int M = 3e5 + 5;
int n, m, a[N], b[M], ans[N];
bool f(int aa[N], int bb) {
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(aa[i] == bb) ans++;
	}
	
	if(ans == 0) return 0;
	else return 1;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    	b[i] = 0;
	}
	for(int k = 1; k <= n; k++) {
	    for(int i = k; i <= n; i++) {
	    	if(a[i] == 0) continue;
	    	ans[i] = a[i];
	    	if(f(ans, a[i]) == 1) {
	    		for(int j = i + 1; j <= n; j++) {
	    			ans[j] = 0;
				}
			} else ans[i + 1] = a[i];
		}
		a[k] = 0;
		for(int l = 1; l <= m; l++) {
			if(ans[l] == l) b[l]++; 
		}
    }
    
    for(int i = 1; i <= m; i++) {
    	cout << b[i] << " ";
	}
	return 0;
}
