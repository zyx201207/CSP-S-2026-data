#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
const int inf=0x3f3f3f3f;
int c,n,m,d,q;
/*
struct edge{
	int to;
	int w;
};
vector<edge> g(maxn);
*/
int w[5005];
int k[5005];
bool a[5005][5005];
int T;
/*
struct node{
	int k;
	int a[5005];
	int t[5005];
};
node kk[5005];
*/
/*
int dis[5005];
bool vis[5005];

void dij(int s){
	int T=kk[1].t[1];
	memset(vis,0,sizeof(vis));
	memset(dis,inf,sizeof(dis));
	dis[s]=0;
	for(int z=1;z<=m;z++){
		int mini=0,min_=inf;//i value
		for(int i=1;i<=n;i++){
			if(!vis[i]&&dis[i]<min_){
				min_=dis[i];
				mini=i;
				vis[i]=1;
			}
			if(mini==0){
				break;
			}
			for(int i=1;i<=n;i++){
				dis[i]=min(dis[mini]+w[mini]+T,dis[i]);
			}
		}
	}
}
*/
int dfs(int x,int y){
	int cnt=0;
	if(x==y){
		return cnt;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	/*
	for(int i=1;i<=n;i++){
		cin>>kk[i].k;
		for(int j=1;j<=kk[i].k;j++){
			cin>>kk[i].a[j]>>kk[i].t[j];
		}
	}
	*/
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>T;	
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dfs(x,y);
		int ans=w[x]+w[y]+2*T;
		cout<<ans<<'\n';
//		dij(x);
//		cout<<dis[y]<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
