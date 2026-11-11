#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
long long n, m, a[200005];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	cout << (a[n] & a[n - 1] & a[n - 2]);
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
