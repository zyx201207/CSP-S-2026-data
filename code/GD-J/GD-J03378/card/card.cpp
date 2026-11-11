#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],c[300010],nex[300010],ans;
int main() {
	ios::sync_with_stdio();cin.tie();cout.tie();
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
		if (!c[a[i]]) c[a[i]]=i;
		else {
			nex[c[a[i]]]=i;
			c[a[i]]=i;
		}
	}
	memset(c,0,sizeof(c));
	for (int i=1;i<=n;i++) {
		for (int j=i;j<=n;j++) {
			while (nex[j]) {
				j=nex[j];
			}
			c[a[j]]++;
		}
	}
	for (int i=1;i<=m;i++) cout << " ";
	return 0;
}
