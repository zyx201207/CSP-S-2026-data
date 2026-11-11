#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int w[500005];
int z[505][500005];
vector<int> k[505];
int vis[500005];
long long cnt=1000000000;
void dfs(int x,int y,int va){
	if(x==y){
		va+=w[y];
		if(va<cnt){
			cnt=va;
		}
		return ;
	}
	vis[x]=1;
	for(int i=1;i<=n;i++){
		if(z[i][x]!=0){
			va+=z[i][x];
			for(int j=0;j<k[i].size();j++){
				if(k[i][j]!=x&&vis[k[i][j]]==0){
					va+=z[i][k[i][j]];
					dfs(k[i][j],y,va);
					va-=z[i][k[i][j]];
					vis[k[i][j]]=0;
				}
			}
			va-=z[i][x];
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int o;
		cin>>o;
		for(int j=1;j<=o;j++){
			int a,t;
			cin>>a>>t;
			z[i][a]=t;
			k[i].push_back(a);
		}
	}
	for(int i=1;i<=p;i++){
		int x,y;
		cin>>x>>y;
		cnt=1000000000;
		memset(vis,0,sizeof(vis));
		dfs(x,y,w[x]);
		cout<<cnt<<endl;
	}
	
}
