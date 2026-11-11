#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=505*2,INF=1e17;
int w[N],dis[N][N];//1~n 地铁口 n~n+d 站台
int l[N][N][2];//存入的数据 
bool f[N][N];//线点 

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=n+d;i++){
		for(int j=1;j<=n+d;j++){
			if(i==j) dis[i][j]=0;
			else dis[i][j]=INF;
		}
	}
	
	for(int i=1;i<=m;i++) cin>>w[i];
	
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			cin>>l[i][j][0]>>l[i][j][1];
			f[k][l[i][j][0]]=1;
			dis[l[i][j][0]][i+d]=l[i][j][1];
			dis[i+d][l[i][j][0]]=l[i][j][1];
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<j;k++){
				if(f[j][i]==f[k][i] && f[j][i]==1){
					dis[j+d][k+d]=l[j][i][0]+l[k][i][0];
					dis[k+d][j+d]=l[j][i][0]+l[k][i][0];
				}
			}
		}
	}
	
	//run floyd
	for(int k=1;k<=n+d;k++){
		for(int i=1;i<=n+d;i++){
			for(int j=1;j<=n+d;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	} 
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
