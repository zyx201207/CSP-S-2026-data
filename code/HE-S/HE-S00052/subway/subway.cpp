#include<bits/stdc++.h>
using namespace std;
const int N = 500+5, M = 5e5+10,D = 21;
const long long INfLl = 52345678912345678LL;
int c,n,m,d,q,w[M],t[N][M],a[M][D],top[M]; 
long long dis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		for(int j=1;j<=k;j++){
			int tmp,tme; cin>>tmp>>tme;
			t[i][tmp]=tme;
			a[tmp][++top[tmp]]=i;
		}
	}
	for(int i=1;i<=n;i++)
	 	for(int j=1;j<=n;j++) dis[i][j]=INfLl;
	for(int i=1;i<=n;i++) dis[i][i]=0;
	
	for(int i=1;i<=m;i++){
		int sz=top[i];
		for(int j=1;j<=sz;j++)
			for(int k=1;k<=sz;k++){
				int u=a[i][j],v=a[i][k];
				//cerr<<u<<" "<<v<<endl;
				dis[u][v]=min(1ll*t[u][i]+1ll*t[v][i],dis[u][v]);
				dis[v][u]=dis[u][v];
			}	
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
//	for(int i=1;i<=n;i++)
//			for(int j=1;j<=n;j++)	cerr<<dis[i][j]<<endl;
	while(q--){
		int x,y; cin>>x>>y;
		long long ans=INfLl;
		for(int i=1;i<=top[x];i++){
			for(int j=1;j<=top[y];j++){
				int u=a[x][i],v=a[y][j];
				ans=min(dis[u][v]+1ll*t[u][x]+1ll*t[v][y]+1ll*w[x]+1ll*w[y],ans);
				//cerr<<u<<"->"<<v<<" "<<dis[u][v]<<" "<<t[u][x]<<" "<<t[v][y]<<" "<<w[x]<<" "<<w[y]<<endl;
			}
		}
		cout<<ans<<endl;
	}
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}// t:路径->点的换乘时间， a[i][j]:经过i点的路径第j条（1<=j<=top[i]） 
