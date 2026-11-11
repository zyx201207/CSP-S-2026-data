#include <iostream>
using namespace std;
int n, m;
int a[500010];
bool b[300010];
int v[300010];
int main () {
	freopen ("card.in", "r" ,stdin);
	freopen ("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=n;i>=1;i--) {
		if (!b[a[i]]) b[a[i]]=true;
		else {
			for (int p=i+1;a[p]!=a[i];p++) a[p]=0;
			b[a[i]]=false;
			v[a[i]]++;
		}
		for (int k=n;k>=i;k--) {
			if (b[a[k]]) v[a[k]]++;
		}
	}
	for (int i=1;i<=m;i++) {
		cout << v[i]<<' ';
	}
	return 0;
}