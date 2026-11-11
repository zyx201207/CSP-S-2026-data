#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,ma;
int a[201000];
vector <int> v;

void dfs (int start,int cnt) {
	if (cnt == m) {
		int sum;
		for (int i = 0;i < v.size();i++) {
			if (i == 0) sum = v[i];
			sum = sum & v[i];
		}
		ma = max(ma,sum);
		return;
	}
	for (int i = start;i <= n;i++) {
		v.push_back(a[i]);
		dfs (i + 1,cnt + 1);
		v.pop_back();
	}
}

int main (void) {
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	
	if (n <= 20) {
		dfs (1,0);
		cout << ma;
		return 0;
	} else if (m == 1) {
		for (int i = 1;i <= n;i++) ma = max (ma,a[i]);
		cout << ma;
		return 0;
	} else if (m == n - 1) {
		sort (a + 1,a + n + 1);
		cout << a[2];
		return 0;
	}
	cout << 0;
	return 0;
}
