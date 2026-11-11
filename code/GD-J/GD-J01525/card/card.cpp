#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int vn[500005];
int vm[300005];
int tem[500005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.in", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> vn[i];
	}
	for (int ju = 1; ju <= n; ju++) {
		int inval = 1; // current point and yihoude point wuxiao
		for (int i = ju; i <= n; i++) {
			int dian = vn[i];
			int pt = lower_bound(tem + 1, tem + inval, dian) - tem;
			if (tem[pt] = dian) {
				inval = pt + 1;
			}
			else {
				tem[inval] = dian;
				inval++;
			}
		}
		for (int i = 1; i <= inval + 1; i++) {
			vm[tem[i]]++;
		}
		for (int i = 1; i <= m; i++) {
			cout << vm[i] << ' ';
		}
		cout << endl;
	}
	for (int i = 1; i <= m; i++) {
		cout << vm[i] << ' ';
	}
	cout << endl;
}
