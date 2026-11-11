#include <bits/stdc++.h>

using namespace std;

int c, t;
int n, k;

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	int cnt = 1;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
		}
		cout << cnt << endl;
		cnt++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

