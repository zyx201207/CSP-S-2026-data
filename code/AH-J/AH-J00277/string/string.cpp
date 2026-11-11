#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
char c[N];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n; scanf("%d", &n);
	
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]); scanf("%s", &c[i]);
	}
	
	int l = 1, r = n;
	long long ln = a[l], rn = a[r], ans = 0;
	
	
	while(l < r) {
		if(c[l] != c[r]) ans += min(ln, rn);
		
		if(ln > rn) {
			ln -= rn;
			rn = 0;
			
			r--;
			rn += a[r];
		} else if(ln < rn){
			rn -= ln;
			ln = 0;
			
			l++;
			ln += a[l];
		} else {
			ln = 0;
			rn = 0;
			
			l++;
			r--;
			
			ln += a[l];
			rn += a[r];
		}
	}
	
	
	cout << ans << '\n';
}
