#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	srand(time(NULL));
	for (int i = 1; i <= m; i++) cout << rand() % m + 1 << " ";
	return 0;
} 
