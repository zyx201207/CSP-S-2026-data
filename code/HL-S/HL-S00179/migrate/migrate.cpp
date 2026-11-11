#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,ans,x[2000005],G[5000][5000],vis[2000005];
int INF=1e9;
bool cc[5000][5000];
queue<int> q;
bool check(int u,int v){
	int flag=0;
	if(cc[u][v]==1||cc[v][u]==1){
		cc[u][v]=cc[v][u]=1;
		return 1;
	}
	if(cc[u][v]==-1||cc[v][u]==-1){
		cc[u][v]=cc[v][u]=-1;
		return 0;
	}
	while(!q.empty()) q.pop();
	memset(vis,0,sizeof(vis));
	q.push(u),vis[u]=1;
	while(!q.empty()){
		int h=q.front(),hh=-1,hhh=-1;
		q.pop();
		if(h==v){
			if(!q.empty()){
				hh=q.front();
				if(hh!=h){
					cc[u][v]=cc[v][u]=-1;
					return 0;
				}
			}else{
				cc[u][v]=cc[v][u]=-1;
				flag++;
				continue;
			}
			
			q.pop();
			if(!q.empty()){
				hhh=q.front();
				q.push(hh);
			}else{
				hhh=-1;
			}
			if((hhh==-1)||(h==hh&&h!=hhh)){
				cc[u][v]=cc[v][u]=1;
				return 1;
			}else{return 0;
			}
		}
		for(int j=1;j<=n;j++){
			if(G[h][j]==1&&!vis[j]){
				vis[j]=1;
				q.push(j);
			}
		}
	}//if(flag==2) return 1;
	return 0;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--) {
		memset(x,0,sizeof(x));
		memset(G,0,sizeof(G));
		cin>>n>>d;
		for(int i=1; i<=n; i++) cin>>x[i];
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(i==j) G[i][j]=G[j][i]=INF;
				else if(abs(x[i]-x[j])<=d) G[i][j]=G[j][i]=1;
				else G[i][j]=G[j][i]=INF;
			}
		}		

		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i<j) ans+=check(i,j);
			}
		}cout<<ans<<endl;
		
	}
	return 0;
}
