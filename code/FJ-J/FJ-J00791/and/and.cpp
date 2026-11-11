#include<bits/stdc++.h>
using namespace std;
int a[200009];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m;
	cin >> n >> m;
	int maxn = 0, minn = INT_MAX;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		maxn = max(maxn,a[i]);
		minn = min(minn,a[i]);
	}
	if (m == 1){
		cout << maxn;
		return 0;
	}
	if (m == 2){
		int maxct = 0;
		for (int i = 1;i <= n;i++){
			for (int j = i + 1;j <= n;j++){
				int ct = 0, x = 1;
				int q = min(a[i],a[j]), p = max(a[i],a[j]);
				while (q != 0){
					if (q % 2 == p % 2){
						ct += x * (q % 2);
					}
					x *= 2;
					q /= 2;
					p /= 2;
				}
				maxct = max(maxct,ct);
			}
		}
		cout << maxct;
		return 0;
	}
	if (m == n){
		sort(a + 1,a + 1 + n);
		for (int i = 1;i < n;i++){
			int ct = 0, x = 1;
			while (a[i] != 0){
				if (a[i] % 2 == a[i + 1] % 2){
					ct += x * (a[i] % 2);
				}
				x *= 2;
				a[i] /= 2;
				a[i + 1] /= 2;
			}
			a[i + 1] = ct;
		}
		cout << a[n];
		return 0;
	}
	cout << minn;
	return 0;
}
