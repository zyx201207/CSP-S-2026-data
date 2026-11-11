#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> a(n+1);
	for (int i=1;i<=n;i++) cin >> a[i];
	vector<int> ans(m+1, 0);
	for (int i=1;i<=n;i++) {
		vector<int> flag(n+1, 0);
		int r=0;
		for (int j=i;j<=n;j++) {
			for (int k=r;k>=1;k--) {
				if (flag[k]==a[j]) {
					r=k-1;
					break;
				}
			}
			flag[++r]=a[j];
		}
		for (int j=1;j<=r;j++) ans[flag[j]]++;
	}
	for (int i=1;i<=m;i++) cout << ans[i] << " ";
	cout << endl;
	return 0;
}
