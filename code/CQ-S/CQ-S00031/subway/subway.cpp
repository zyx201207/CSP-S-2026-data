#include <bits/stdc++.h>
#define name "subway"
using namespace std;
const int N=507,M=500007;
typedef long long li;
li f[N][N],w[M],sz[M];
vector<li> a[M],t[M];
const li inf=0x3f3f3f3f3f3f3f3f;
int main(){
	freopen(name".in","r",stdin);
	freopen(name".out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[x].push_back(i);
			t[x].push_back(y);
			sz[x]++;
		}
	}
	memset(f,'?',sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<sz[i];j++) for(int k=j+1;k<sz[i];k++){
			int u=a[i][j],v=a[i][k];
			li w=t[i][j]+t[i][k];
			f[u][v]=min(f[u][v],w);
			f[v][u]=min(f[v][u],w);
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int k=1;k<=n;k++) f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
	for(int i=1;i<=q;i++){
		li ans=inf;
		int x,y;
		cin>>x>>y;
		for(int j=0;j<sz[x];j++) for(int k=0;k<sz[y];k++) ans=min(ans,w[x]+w[y]+t[x][j]+t[y][k]+f[a[x][j]][a[y][k]]);
		cout<<ans<<'\n';
	}
	return 0;
} 
/*
CSP-S rp += inf
NOIP rp += inf
Never give up any problems as I have lost NOIP2025.
See ancestors on Halloween at /discuss/898803.
//froepen
//ferepen
//retrun
que
queue
queueue
queueueue
queueueueue
*/
