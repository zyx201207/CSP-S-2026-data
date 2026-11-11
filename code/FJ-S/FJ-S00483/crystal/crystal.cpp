#include<bits/stdc++.h>
using namespace std;
long long n, m, x, num1 = 0, num2 = 0;
bool flag1 = true, flag2 = true;
vector<long long> a;
vector<long long> b;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	for (int i = 1; i < n; i++) {
		b.push_back(a[i] - a[i - 1]);
	}
	int lenth = b.size();
	int max1 = 0, max2 = 0, maxx1 = 0, maxx2 = 0;
	for (int i = 0; i < lenth; i++) {
		num1 = 0;
		num2 = 0;
		for (int j = i; j < lenth; j++) {
			num1 += b[j] * (j - i + 1);
		}
		for (int j = 0; j < lenth - i; j++) {
			num2 += b[j] * (j + 1);
		}
		if (num1 <= m) {
			if (num1 > maxx1) {
				max1 = lenth - i + 1;
				maxx1 = num1;
			}
		}
		if (num2 <= m) {
			if (num2 > maxx2) {
				max2 = lenth - i + 1;
				maxx2 = num2;
			}
		}
		if (num1 <= m && num2 <= m) break;
	}
	cout << (max1 > max2 ? max1 : max2);
	return 0;
}
