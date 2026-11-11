#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[100005],a[100005][100005],t[100005][100005];
int main() {
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) {
		cin>>w[i];
	}
	for (int i=1;i<=n;i++) {
		int x;cin>>x;
		for (int j=1;j<=x;j++) {
			int y,z;
			cin>>y>>z;
			a[i][j]=y;
			t[i][j]=z;
		}
	}
	while (q--) {
		int s,f;
		cin>>s>>f;
	}

	return 0;
}  
