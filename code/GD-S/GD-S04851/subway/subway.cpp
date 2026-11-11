#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
int c,n,m,d,q,o,l,r,mn,k[505],hd[505],bz[505],w[500005],p[1000005],to[500005],nt[500005],qz[500005],f[505][505];
vector<int>a[500005],b[500005];
void add(int x,int y,int z){
	nt[++o]=hd[x],to[o]=y;
	qz[o]=z,hd[x]=o;
}
void bfs(int d){
	for(int i=1;i<=n;i++) bz[i]=0;
	bz[d]=l=r=1,p[1]=d,f[d][d]=0;
	while(l<=r){
		for(int i=hd[p[l]];i;i=nt[i]){
			if(f[d][to[i]]<=f[d][p[l]]+qz[i]) continue;
			f[d][to[i]]=f[d][p[l]]+qz[i];
			if(bz[to[i]]) continue;
			bz[to[i]]=1,p[++r]=to[i];
		}
		bz[p[l]]=0,l++;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,x,y;j<=k[i];j++){
			cin>>x>>y;
			a[x].pb(i),b[x].pb(y);
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=1e18;
	for(int i=1;i<=m;i++){
		int t=a[i].size();
		for(int j=0;j<t;j++) for(int l=j+1;l<t;l++)
			if(f[a[i][j]][a[i][l]]>b[i][j]+b[i][l])
				f[a[i][j]][a[i][l]]=f[a[i][l]][a[i][j]]=b[i][j]+b[i][l];
	}
	for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++){
		if(f[i][j]==1e18) continue;
		add(i,j,f[i][j]),add(j,i,f[i][j]);
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=1e18;
	for(int i=1;i<=n;i++) bfs(i);
	while(q--){
		cin>>l>>r,mn=1e18;
		int u=a[l].size(),v=a[r].size();
		for(int i=0;i<u;i++) for(int j=0;j<v;j++)
			mn=min(mn,f[a[l][i]][a[r][j]]+b[l][i]+b[r][j]);
		cout<<mn+w[l]+w[r]<<"\n";
	}
	return 0;
}
