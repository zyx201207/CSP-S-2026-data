#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[10010],k[10010],a[10010][10010],t[10010][10010],s[100010],e[100010];
vector<int> v[10010],g[10010];
int vis[1000]={},vis1[10010];
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar(); 
	}
	return x*f;
}
int bfs(int x,int y){
	queue<int>q;
	memset(vis1,0,sizeof(vis1));
	for(int i=0;i<v[x].size();i++){
		q.push(v[x][i]);
		vis1[v[x][i]]=1;
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<v[y].size();i++){
			if(u==v[y][i]){
				return vis1[u]-1;
			}
		}
		for(int i=0;i<g[u].size();i++){
			if(vis1[g[u][i]]==0){
				vis1[g[u][i]]=vis1[u]+1;
				q.push(g[u][i]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			v[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>s[i]>>e[i];
	}	
//	if(c>=1&&c<=3){
//		for(int i=1;i<=q;i++){
//			int ans=w[s[i]]+w[e[i]];
//			cout<<ans<<"\n";	
//		}return 0;
//	}
//	if(c>=12&&c<=19){
//		for(int i=1;i<=q;i++){
//			int ans=w[s[i]]+w[e[i]];
//			for(int i=1;i<=m;i++){
//				for(int j=0;j<=v[i].size();j++){	
//					for(int u=0;u<=v[i].size();u++){
//						if(j!=u){
//							g[j].push_back(u);
//						}
//					}
//				}
//			}
//			int l=bfs(s[i],e[i]);
//			cout<<t[1][1]*l+ans<<"\n";
//		}
//		return 0;
//	}
	for(int i=1;i<=q;i++){
		int ans=w[s[i]]+w[e[i]];
		cout<<ans<<"\n";
	}
	
}
