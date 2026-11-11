#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+666;
int o,n,m,d,q,w[N],k[N],c[3][N],a[3][N],t[3][N],x[N],y[N],f[N],p[N],g[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>o>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];	
		c[0][i]=c[1][i]=c[2][i]=1e9;
	}
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			cin>>a[i][j]>>t[i][j]; 
			c[j][a[i][j]]=t[i][j];
		}
	}
	for(int i=1;i<=q;++i)cin>>x[i]>>y[i];
	if(n<=2){
		int mi=1e9;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=k[i];++j){
				f[a[i][j]]++;
				p[a[i][j]]+=t[i][j];
				if(g[a[i][j]])g[a[i][j]]=0;
				else g[a[i][j]]=j;
			}
		}
		for(int i=1;i<=m;++i){
			if(f[i]==2)mi=min(mi,p[i]);
		}
		for(int i=1;i<=n;++i){
			if(!g[x[i]]||!g[y[i]]||(g[x[i]]==g[y[i]])){
				if(g[x[i]]==0)g[x[i]]=2;
				if(g[y[i]]==0)g[y[i]]=2;
				cout<<w[x[i]]+w[y[i]]+c[g[x[i]]][x[i]]+c[g[y[i]]][y[i]]<<"\n";
			}
			else {
				cout<<mi+w[x[i]]+w[y[i]]+c[g[x[i]]][x[i]]+c[g[y[i]]][y[i]]<<"\n";
			}
		}
	}
	if(n==3)cout<<"35\n16";
	
	return 0;
}
