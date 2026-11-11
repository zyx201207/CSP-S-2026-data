#include<bits/stdc++.h>
//#define F(i,a,b) for(register int i=a;i<=b;i=-~i)
#define F(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
using namespace std;const int N=5e2+5,M=5e5+5,D=25,Q=1e5+5;
int c,n,m,d,q;ll w[M],k[M],a[N][D],t[N][D],mina,g[1005][1005];bool vis[1005][1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	F(i,1,m)cin>>w[i];
	F(i,1,n){
		cin>>k[i];
		F(j,1,k[i])cin>>a[i][j]>>t[i][j];
		F(x,1,k[i]-1)F(y,x+1,k[i])g[a[i][x]][a[i][y]]=g[a[i][y]][a[i][x]]=t[i][x]+t[i][y];
	}
	F(i,1,m){
		F(j,1,m){
			F(k,1,m){
				if(i!=j&&j!=k&&i!=k){
//					if(i==1&&j==2)cout<<g[i][j]<<' '<<a[i][k]<<' '<<g[k][j]<<" "<<i<<' '<<j<<" "<<k<<'\n';
					if(g[i][j]==0)vis[i][j]=vis[j][i]=1,g[i][j]=g[j][i]=g[i][k]+g[k][j];
					if(vis[i][j]==1&&vis[i][k]==0&&vis[k][j]==0)g[i][j]=g[j][i]=min(g[i][k]+g[k][j],g[i][j]);
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
//		cout<<w[x]<<' '<<w[y]<<"<<<\n";
		cout<<w[x]+w[y]+g[x][y]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
