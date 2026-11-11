#include <bits/stdc++.h>
using namespace std;
const int N=5e2+5;
long long n,m,w[N],k[N],a[N][N],t[N][N],x[N],y[N],c,d,q;
int ans=0;
void dfs(int f,int l) {
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			if(f==a[i][j]) {
				if(f==l) {
					return;
				} else {

				}
			}

		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=k[i]; j++) {
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1; i<=q; i++) {
		cin>>x[i]>>y[i];
		cout<<ans<<endl;
	}
	return 0;
}
