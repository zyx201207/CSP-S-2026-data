#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	long long a, sum = 0, res = 0;
	char c;
	string ans;
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a >> c;
		sum += a;
		for(int j = 1; j <= a; j ++) {
			ans += c;
		}
	}
	for(int i = 0; i < sum; i ++) {
		if(ans[i] != ans[sum - 1 - i]) {
			ans[sum - 1 - i] == ans[i];
			res ++;
		} 
		if(i > sum - 1 - i) {
			break;
		}
	}
	cout << (res + 1) / 2 << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
