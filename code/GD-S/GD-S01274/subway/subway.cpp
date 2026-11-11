#include<bits/stdc++.h>
using namespace std;
#define int long long
struct sd{
	int y,z;
};
int c,n,m,d,q;
vector<sd> v[514514];
int w[514514];
int g[514][514];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,z;
			cin>>x>>z;
			v[x].push_back({i,z});
		}
	}memset(g,0x3f,sizeof g);
	for(int i=1;i<=n;i++){
		g[i][i]=0;
	}for(int i=1;i<=m;i++){
		for(int l=0;l<signed(v[i].size())-1;l++){
			for(int r=l+1;r<signed(v[i].size());r++){
				int p=v[i][l].z+v[i][r].z;
				if(p<g[v[i][l].y][v[i][r].y]){
					g[v[i][l].y][v[i][r].y]=p;
					g[v[i][r].y][v[i][l].y]=p;
				}
			} 
		}
	}for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j || k==i || k==j)continue;
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int sum=w[x]+w[y],mini=1e18;
		for(int l=0;l<signed(v[x].size());l++){
			for(int r=0;r<signed(v[y].size());r++){
				mini=min(mini,v[x][l].z+v[y][r].z+g[v[x][l].y][v[y][r].y]);
			}
		}sum+=mini;
		cout<<sum<<"\n";
	}
	return 0;
} 
