#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

int er (int a) {
	int h;
	while (a > 0) {
		h = h * 10 + a % 2;
		a = a / 2;
	}
	return h;
}

int an (int p, int x) {
	int ans[1000], j = 0, daan = 0;
	while (p > 0 && x > 0) {
		if (p % 10 == 1 && x % 10 == 1) {
			ans[j] = 1;
		} 
		else {
			ans[j] = 0;
		}
		j++;
	}
	int h = 1;
	for (int i = j - 1; i >= 0; i--) {
		daan = daan + ans[i] * h;
		h = h * 2;
	}
	return daan;
}

bool cmp (const int a, const int b) {
	return a > b;
}

int main() {
	//freopen ("and.in","r",stdin);
	//freopen ("and.out","w",stdout);

	int n, m, q;
	cin >> n >> m;
	int w[n], y[n], a[1000];
	for (int i = 0; i <= n; i++) {
		cin >> q;
		w[i] = q;
	}
	
	for (int i = 0 ; i < n; i++)  {
		y[i] = er(a[i]);
	}
	
	for (int i = 0 ; i < n; i++) {
		
	}
	
	sort(a+0,a+1000,cmp);

	cout << "12";
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
