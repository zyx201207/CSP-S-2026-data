#include <bits/stdc++.h>
using namespace std;
char a[100000005] = {0};

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	long long sum = 0;
	long long xiu = 0;
	for (int i = 0; i < n; i++) { //ÊäÈë²¿·Ö 
		long long s;
		char c;
		cin >> s >> c;
		for (int j = sum; j < sum + s; j++) a[j] = c;
		sum += s;
	}
	for (int i = 0; i < sum / 2; i++) {
		if (a[i] != a[sum - i - 1]) xiu++;
	}
	cout << xiu;
	return 0;
}
