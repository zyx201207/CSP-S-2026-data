//GZ-J00667 遵义市第十二中学 陈俊熙
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
const int M = 3e5 + 10;
int n, m;
int a[N], cnt[M];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		vector<int> b(n + 1);
		for (int j = i - 1; j < n; j++) {
			int it = -1;
			for (int z = 0; z < b.size(); z++) {
                if (a[j] == b[z]) {
                    it = z;
                }
			}
			if (it == -1) {
				b.push_back(a[j]);
			} else {
				for (int k = it; k < b.size(); k++) {
					b.pop_back();
				}
				b.push_back(a[j]);
			}
		}
		for (int g = 0; g < b.size(); g++) {
            cnt[b[g]]++;
		}
	}

	for (int i = 1; i <= m; i++) {
        cout << cnt[i] << " ";
	}
	return 0;
}
