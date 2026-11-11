#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
vector<int> g[5005];
long long w[500005],y[500005],z[500005],flag[500005];
void dfs(int x,int ans) {
	if(ans<y[x]) return;
	if(ans<y[x]) {
		z[x]++;
		cout<<x<<z[x];
	}
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.cout","w",stdout);
	cin>>c>>t;
	while(t--) {
		memset(y,0x3f3f3f3f3f3f3f3f,sizeof(y));
		memset(y,0,sizeof(z));
		for(int i=1; i<=5005; i++) g[i].clear();
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(abs(w[i]-w[j])<=d) {
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}

	}

	memset(f,0x3f3f3f3f3f3f3f3f,sizeof(f))
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=k[i]; j++) {
			cin>>a[i][j]>>C[i][j];
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=k[i]; j++) {
			if(j!=1) {
				f[a[i][j]][a[i][j-1]]=min(f[i][j]][a[i][j-1]],C[i][j-1]+c[i][j]]);
				f[a[i][j-1]][a[i][j]]=min(f[i][j-1]][a[i][j]],C[i][j]+c[i][j]);
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			for(int k=1; k<=n; k++) {
				f[i][k][k]=min(f[j][k][k],f[i][k][k]);
			}
		}
	}
	for(int i=1; i<=p; i++) {
		cin>>x>>y;
		cout<<f[x][y]+w[x];
	}
	int ans=1;
	int l=1,r=n;
	while(l<=r) {
		int mid=(l+r)/2;
		if(check(mid)) {
			ans=mid;
			l=mid+1;
		} else {

		}
	}
	return 0;
}
