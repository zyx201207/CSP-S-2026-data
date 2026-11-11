#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
long long n, a[200005];
char c[200005];
long long l = 1, r, ans = 0;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	long long pl = 1, pr = n, sl = 0, sr = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d %c", &a[i], &c[i]);
		r += a[i];
	}
	while(pl < pr) {
		sl += a[pl];
		sr += a[pr];
		if(sl == sr) {
			if(c[pl] != c[pr]) {
				ans += a[pl];
			} 
			pl++;
			pr--;
		} else {
			if(sl > sr) {
				a[pl] = sl - sr;
				sl = sr;
				if(c[pl] != c[pr]) {
				ans += a[pr];
				}
				pr--;
			}
			if(sl < sr) {
				a[pr] = sr - sl;
				sr = sl;
				if(c[pl] != c[pr]) {
				ans += a[pl];
				}
				pl++;
			}
		}
	}
	cout << ans <<endl;
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 

