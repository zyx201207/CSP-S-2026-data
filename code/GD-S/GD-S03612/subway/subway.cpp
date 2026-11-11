#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
struct edge{
	int s,t;
};
int c,n,m,d,q,w[M],ans=0x3f3f3f3f;
map<int,int>g[M];//出厅时间 
bool vis[N],vis2[N];
vector<int>f[N];//所在线路 
vector<int>de[N];//所有站台 
vector<int>dd[N];//可换乘站台 
void dfs(int x,int y,int sum,int c){
	int cnt=0;
	for(int s:f[x]){
		if(vis[s])
			continue;
		for(int j:de[s]){
			if(j==y){
				ans=min(ans,sum+g[x][s]+g[j][s]);
				vis2[x]=false;
				return;
			}
		}
		vis[s]=true;
		vis2[x]=true;
		for(int j:dd[s])
			if(!vis2[j]){
				dfs(j,y,sum+g[x][s]+g[j][s],c+1);
		vis[s]=false;
		vis2[x]=false;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int lstx=0;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			de[i].push_back(x);
			g[x][i]=y;
			f[x].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		int lstx=0;
		for(int j:de[i])
			if(g[j].size()>1)
				dd[i].push_back(j);
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ans=0x3f3f3f3f;
		memset(vis,false,sizeof(vis));
		memset(vis2,false,sizeof(vis2));
		dfs(x,y,0,1);
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
} 
