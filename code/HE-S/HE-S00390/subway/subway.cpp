#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5,D=25;
long long c,n,m,d,q,t[M],cd[M],cv[M][D],cw[M][D],f[N][N];
void Floyd(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>q;memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++)
		cin>>t[i];
	for(int i=1,k;i<=n;i++){
		cin>>k,f[i][i]=0;
		for(int j=1,a,t;j<=k;j++)
			cin>>a>>t,cd[a]++,cv[a][cd[a]]=i,cw[a][cd[a]]=t;
	}
	for(int i=1;i<=m;i++)
		for(int u=1;u<=cd[i];u++)
			for(int v=1;v<=cd[i];v++)
				f[cv[i][u]][cv[i][v]]=min(f[cv[i][u]][cv[i][v]],cw[i][u]+cw[i][v]);
	Floyd();
	while(q--){
		int u,v;
		cin>>u>>v;
		long long ans=f[0][0];
		for(int i=1;i<=cd[u];i++)
			for(int j=1;j<=cd[v];j++)
				ans=min(ans,f[cv[u][i]][cv[v][j]]+cw[u][i]+cw[v][j]);
		cout<<ans+t[u]+t[v]<<"\n";
	}
	return 0;
}
