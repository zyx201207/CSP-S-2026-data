#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+66;
int m,w[N],n,k[N],t[N][N],a[N][N],q,d,c,x,y;
bool f[N][N];
int dis[N][N];
int tim;
bool p=1;
vector<int>pos[N];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof dis);
	for(int i=1; i<=m; i++) cin>>w[i];
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=2*k[i]; j++) {
			cin>>a[i][j]>>t[i][j];
			tim=t[i][j];
			f[a[i][j]][a[i][j-1]]=f[a[i][j-1]][a[i][j]]=1;
			dis[a[i][j]][a[i][j-1]]=dis[a[i][j-1]][a[i][j]]=1;
		}
	}
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				f[i][j]=f[i][k]&&f[k][j];
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
	while(q--) {
		int ans=0;
		cin>>x>>y;
		ans=ans+w[x]+t[x][x]+w[y];
		ans=ans+(dis[x][y]*2-1)*tim;
		cout<<ans;
	}
	return 0;
}
/*

*/
