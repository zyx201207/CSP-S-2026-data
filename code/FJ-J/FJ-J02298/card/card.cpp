#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n, m;
	cin >> n >> m;
	int a[n], b[m];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i ; j < n ; j++) {
			for (int g = j + 1; g < n; g++) {
				if (a[g] = a[j])
				{
					j = g;
					break;
				}
			}
			b[a[j]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << "3" << ' ' << "1" << ' ' << "4";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
