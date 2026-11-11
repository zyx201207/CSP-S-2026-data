#include<bits/stdc++.h>
using namespace std;
const int M=1e6,N=505,K=4e5+10;
int c,n,m,d,q,bb;
int w[M],k[N];
int a[N][K],t[N][K],f[N];
long long dis[N][N],ans,add;
struct node{
	int y,w;
};
vector<node>e[M];
void dfs(int x,int y,int b,long long len){
	if(x==y){
		add=min(add,len);
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[k[i]]!=b&&dis[x][k[i]]){
			f[k[i]]=b;
			dfs(k[i],y,b,len+dis[x][k[i]]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(dis,1e9,sizeof dis);
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			for(int z=0;z<e[a[i][j]].size();z++){
				dis[e[a[i][j]][z].y][i]=dis[i][e[a[i][j]][z].y]=min(dis[e[a[i][j]][z].y][i],(long long)(t[i][j]+e[a[i][j]][z].w));
			e[a[i][j]].push_back({i,t[i][j]});
			}                      
		}
	}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		ans=w[x]+w[y],add=1e9;
		for(int o=0;o<e[x].size();o++){
			for(int p=0;p<e[y].size();p++){
				if(dis[e[x][o].y][e[y][p].y]){
					add=min(add,dis[e[x][o].y][e[y][p].y]);
				}
			}
		}
		cout<<ans+add<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

