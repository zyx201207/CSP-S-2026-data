#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=505;
struct node{
	int to;
	int much;
}q[N][530][M];
int c;
int n,m,d,qu,k,a[N],t[N],u[N],v[N],tn[N],st,nd,f[N][M],vis[N];
queue <int> p;
int bfs(int x,int y){
	p.push(x);
	vis[x]=1;
	for(int o=1;o<=tn[x];o++){
		f[x][o]=q[x][1][o].much;
		while(!p.empty()){
			int h=p.front();
			p.pop();
			for(int i=1;i<=t[h];i++){
				for(int j=1;j<=tn[h];j++){
					if(vis[q[h][i][j].to]==0){
						int l=q[h][i][j].to;
						vis[l]=1;
						p.push(l);
						if(l!=h) f[l][j]=min(f[l][j],f[h][j]+q[l][i][j].much);
						if(l==h){
							for(int b=1;b<=tn[l];h++) f[l][j]=min(f[l][j],f[h][j]+q[l][i][b].much);
						}
					}
				}
			}
		}
	}
	int ans=INT_MAX;
	for(int i=1;i<=tn[y];i++) ans=min(ans,f[y][i]);
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qu;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>u[j]>>v[j];
		}
		for(int j=1;j<=k;j++){
			tn[u[j]]++;
			q[u[j]][++t[j]][tn[j]].much=v[j];
			for(int o=1;o<=k;o++){
				if(j!=o){
					q[u[j]][++t[u[j]]][tn[u[j]]].to=u[o];
					if(tn[u[j]]>1) q[u[j]][++t[u[j]]][tn[u[j]]].to=u[o];
				}
			}
		}
	}
	while(qu--){
		cin>>st>>nd;
		memset(f,0x3f,sizeof(f));
		memset(vis,0,sizeof(vis));
		cout<<bfs(st,nd)+a[st]+a[nd];
	}
	return 0;
} 
