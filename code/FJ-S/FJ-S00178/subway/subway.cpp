#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
const int M=5e5 +5;
ll c,n,m,d,q,f[N][N],qwq[M],g[M][25],w[M][25],cnt[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>qwq[i];
	for(int i=1,k,u,ww;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>u>>ww;
			g[u][++cnt[u]]=i;
			w[u][cnt[u]]=ww;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=1e15;
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++){
		int x=cnt[i];
		for(int j=1;j<=x;j++){
			for(int k=j+1;k<=x;k++){
				f[g[i][j]][g[i][k]]=f[g[i][k]][g[i][j]]=w[i][j]+w[i][k];
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//			cout<<f[i][j]<<" ";
//		cout<<"\n";
//	}
	while(q--){
		int x,y;ll ans=1e15;
		cin>>x>>y;
		int s1=cnt[x],s2=cnt[y];
		for(int i=1;i<=s1;i++){
			for(int j=1;j<=s2;j++){
				ans=min(ans,f[g[x][i]][g[y][j]]+w[x][i]+w[y][j]);
			}
		}
		cout<<ans+qwq[x]+qwq[y]<<"\n";
	}
	return 0;
}
