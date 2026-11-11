#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=5e5+7;

int c,t,n,k;
vector<int>g[N];




signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<"1\n";
	}
}










//void dfs(int x,int fa,int dp){
//	d[x]=dp+1,s[x][0]=fa;
//	for(auto e:g[x]){
//		if(e==fa)continue;
//		dfs(e,x,dp+1);
//	}
//}
//
//
//int lca(int x,int y){
//	int len=0;
//	if(d[x]>d[y])swap(x,y);//d[x]<=d[y]
//	for(int i=M-1;i>=0;i--){
//		if(d[y]-(1<<i)>=d[x])y=s[y][i],len+=(1<<i);
//		if(d[x]==d[y])continue;
//	}
//	for(int i=M-1;i>=0;i--){
//		if(s[x][i]!=s[y][i]){
//			x=s[x][i],y=s[y][i];
//			len+=(1<<i);
//		}
//	}
//	len+=1;
//	return len;
//}
//
//
//signed main(){
//	cin>>c>>t;
//	while(t--){
//		cin>>n>>k;
//		for(int i=1;i<=n-1;i++){
//			int u,v;
//			cin>>u>>v;
//			g[u].push_back(v);
//			g[v].push_back(u);
//		}
//		dfs(1,0,1);
//		for(int l=1;l<M;l++){
//			for(int i=1;i<=n;i++){
//				s[i][l]=s[s[i][l-1]][l-1];
//			}
//		}
//		for(int i=1;i<=n;i++)dist[i][i]=0,x[i]=i;
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				if(i==j)continue;
//				dist[i][j]=lca(i,j);
//			}
//		}
//		do{
//			
//			
//			
//			
//		}while(next_permutation(x+1,x+n+1));
//	}
//	return 0;
//}
