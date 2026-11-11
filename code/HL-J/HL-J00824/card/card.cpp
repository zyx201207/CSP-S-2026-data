#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int tms[500005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		tms[a[i]]++;
	}
	for(int i=1;i<=m;i++) {
		if(i==a[n]) cout << n <<" ";
		else cout << tms[i] << " ";
	}
	return 0;
}
//Why not this world takes me away to heaven?