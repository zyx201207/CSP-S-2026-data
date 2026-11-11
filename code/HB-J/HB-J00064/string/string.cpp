#include <iostream>
#include <vector>
using namespace std;

int n; vector<char> v;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
	cin >> n; v.push_back('0');
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		int ai; char ci;
		cin >> ai >> ci; sum += ai;
		for (int j = 1; j <= ai; j++) v.push_back(ci);
	}
	int ans = 0;
	for (int i = 1; i <= sum / 2; i++)
		if (v[i] != v[sum - i + 1])
			ans++;
	cout << ans;
    return 0;
}
