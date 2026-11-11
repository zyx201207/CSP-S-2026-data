#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n];
	for(int i = 0;i < n;i++) cin >> a[i];
	for(int i = 0;i < n;i++) cout << i * 2 + 3 << ' ';
	cout << endl;
	return 0;
}

