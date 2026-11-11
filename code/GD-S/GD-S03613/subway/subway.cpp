#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200,M=5e5;
int c,n,m,d,q,w[M+5];
struct node{
	int v,w;
};
int g[N+5][M+5];
int gg[N+5][N+5];
//int dfn[M+5],low[M+5],timer;
//stack <int>st;
//bool ex[M+5];
//int col[M+5],cnt;
void init(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			g[i][j]=1e9;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			gg[i][j]=1e9;
	return;
}
signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	init();
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,w;
			cin>>v>>w;
			g[i][v]=w;
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=m;k++)
				for(int t1=1;t1<=n;t1++)
					for(int t2=1;t2<=n;t2++){
						if(i==j || j==k || i==k)
							continue;
						if(g[t1][i]+g[t1][k]+g[t2][k]+g[t2][j]<gg[i][j])
							gg[i][j]=g[t1][i]+g[t1][k]+g[t2][k]+g[t2][j];
						if(g[t1][i]+g[t1][j]<gg[i][j])
							gg[i][j]=g[t1][i]+g[t1][j];
					}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=m;k++){
				if(i==j || k==j || i==k)
					continue;
				gg[i][j]=min(gg[i][k]+gg[k][j],gg[i][j]);
			}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		cout<<w[x]+gg[x][y]+w[y]<<'\n';
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

8+4+6+1+2+7+9
*/
