#include <bits/stdc++.h>
#include <iostream> 
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
	freopen ("string3.in","r",stdin);
	freopen ("string.out","w",stdout);
	
	
	string S, ci;
	long long int n, ai, j, ans = 0;
	cin >> n;
	int size = 0;
	for (int i = 0; i < n; i++) {
		j = 0;
		cin >> ai ;
		cin >> ci;
		size += ai;
		while (j < ai) {
			S += ci;
			j++;
		}
	}
	cout << size << endl;
	for (int i = 0 ;i < n / 2 + 1; i++) {
		if (S[i] - 97 != S[size - i - 1] - 97) {
			ans++;
		}
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
