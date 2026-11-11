#include<bits/stdc++.h>
using namespace std;
int ty[500005][25],cnt[500005];
int c,n,m,d,p,w[500005],a[505][500005],k[505],t[505][500005],x,y,vis[500005];
void bfs(int x){
	queue<int> q;
	q.push(x);
	vis[x]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=1;i<=cnt[x];i++){
			int xx=ty[x][i];
			for(int j=1;j<=k[xx];j++){
				if(vis[a[xx][j]]==0){
					q.push(a[xx][j]);
					vis[a[xx][j]]=vis[x]+1;
				}
			}
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
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			ty[j][++cnt[j]]=i;
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=p;i++){
		cin>>x>>y;
		if(c>=12&&c<=19){
			memset(vis,0,sizeof(vis));
			bfs(x);
			int ans=w[x]+w[y]+(vis[y]-1)*2*t[i][1];
			cout<<ans<<"\n";
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

