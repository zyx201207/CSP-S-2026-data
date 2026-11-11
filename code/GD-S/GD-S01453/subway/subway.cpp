#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[500005],k[505],a[505][50005],t[505][50005];
int x[10005],y[10005];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=2*k[i]; j++) {
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1; i<=q; i++) {
		cin>>x[i]>>y[i];
		int r=x[i],l=y[i];
		int tim=0;
		tim=tim+w[x[i]]+w[y[i]];
		for(int j=1; j<=k[i]; j++) {
			if(r<l) {
				tim=tim+t[x[i]][x[j]];
				if(i<j) {
					i++;
					j--;
					r++;
				}
			} else {
				continue;
			}
		}
		cout<<tim<<endl;
	}


	return 0;
}
