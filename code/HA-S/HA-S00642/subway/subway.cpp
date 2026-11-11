#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int ans;
int w[50005],k[505];
bool b[500005];
int a[5005][5005],t[5005][5005];
struct point{
	int way,wh;
}o[50005];
void dfs(int u,int e){
	if(u==e){
		cout<<ans+w[e];
		return ;
	}else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==u){
					ans+=t[i][j];
					for(int p=1;p<=k[i];p++){
						if(j!=p&&b[a[j][p]]==0){
							b[a[j][p]]=1;
							ans+=t[j][p];
							dfs(a[j][p],e);
							ans-=t[j][p];
						}
					}
				}
			}
		}
	}
}
//priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
//void dji(int s,int e){
//	q.qush({0,s});
//	while(!q.empty()){
//		int len=q.top().first;
//		int k=q.top().second;
//		if(k==e) continue;
//		for(int j=h[k];j;j=nxt[j]){
//			int v=to[j];
//			if(dis[i][j]>dis[i][v]+len{
//				dis[i][j]=dis[i][v]+len;
//				q.push({dis[v],v});
//			}
//		}
//	}
//	
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		dfs(x,y);	
		//dji(x[i],y[i]);
	}
	
return 0;
}
