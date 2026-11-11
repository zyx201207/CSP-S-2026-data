#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,far;
int t[5002][5002],w[5002],k[5002];
bool vis[5005][5005],vis2[5005][5005];
void dfs(int start,int end,int u){
	if(start==end){
		far=min(far,u);
	}
	for(int i=1;i<=m;++i){
		if(vis[start][i]==1&&vis2[i][start]!=1){
			vis2[start][i]=vis2[i][start]=1;
			dfs(i,end,u+t[start][i]);
			vis2[start][i]=vis2[i][start]=0;
		}
	}
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i){
    	cin>>w[i];
    }
    for(int i=1;i<=n;++i){
    	cin>>k[i];
    	for(int j=1;j<=k[i];++j){
    		int a;
    		cin>>a>>t[i][a];
    		t[i][a]=t[a][i];
    		vis[i][a]=1;
    		vis[a][i]=1;
    		
    	}
    }
    for(int i=1;i<=q;++i){
    	int x,y;
    	far=0;
    	cin>>x>>y;
    	dfs(x,y,0);
    	cout<<far+w[x]+w[i]<<endl;
    }
}
//vis[i][j]是否能通行 
//t[i][a]第i条线到A的距离 
