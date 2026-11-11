#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,m,n,d,q;
const int N=520;
int u,v,w1,w2;
int g[N][N];
int a[N];



signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	if(c<=19&&c>=12){
		
	}else if(c<=11&&c>=7){
		cout<<q;
		memset(g,0x3f,sizeof g);
		for(int i=1;i<=n;i++){
			cin>>a[i];
			g[i][i]=0;
		}
		int k;
		for(int i=1;i<=m;i++){
			cin>>k;
			if(k==1){
				int fw1,fw2;
				cin>>fw1>>fw2;
			}else{
				//for(int j=1;j<=k;j++){
					cin>>u>>w1>>v>>w2;
					g[u][v]=min(g[u][v],w1+w2);
					g[v][u]=min(g[v][u],w1+w2);
				//}
			}			
		}
		//cout<<q;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
				}
			}
		}
		for(int i=1;i<=q;i++){
			cin>>u>>v;
			cout<<g[u][v]+a[u]+a[v]<<'\n';
		}
	}else if(n<=3){
		
	}
	return 0;
}
