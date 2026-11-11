#include<bits/stdc++.h>
#define ll long long
using namespace std;
//long long!!!!
int tstid,n,m,d,q;
ll w[500010];
struct walk {
	ll ln,c;
} sta[500010][25];
ll sz[500010];
ll f[510][510];
ll minn(ll x,ll y) {
	if(x<y) return x;
	return y;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>tstid>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) {
		int k;
		cin>>k;
		for(int j=1;j<=k;j++) {
			ll v,cst;
			cin>>v>>cst;
			sz[v]++;
			sta[v][sz[v]].ln=i;
			sta[v][sz[v]].c=cst;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j) f[i][j]=1e18;
//	for(int i=1;i<=m;i++) cout<<sz[i]<<"\n";
	for(int i=1;i<=m;i++) {
		for(int j=1;j<sz[i]&&j<=d;j++) {
			for(int k=j+1;k<=sz[i]&&k<=d;k++) {
				f[sta[i][j].ln][sta[i][k].ln]=minn(f[sta[i][j].ln][sta[i][k].ln],sta[i][j].c+sta[i][k].c);
				f[sta[i][k].ln][sta[i][j].ln]=minn(f[sta[i][k].ln][sta[i][j].ln],sta[i][j].c+sta[i][k].c);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=minn(f[i][j],f[i][k]+f[k][j]);
	while(q--) {
		int u,v;
		ll ans=1e18;
		cin>>u>>v;
		for(int i=1;i<=sz[u]&&i<=d;i++) 
			for(int j=1;j<=sz[v]&&j<=d;j++) 
				ans=minn(ans,sta[u][i].c+sta[v][j].c+f[sta[u][i].ln][sta[v][j].ln]);	
		cout<<w[u]+w[v]+ans<<"\n";
	}
	return 0;
}
// fc subway.out subway4.ans
