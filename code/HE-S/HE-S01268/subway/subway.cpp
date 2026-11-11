#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+7;
int cnt,a[(maxn<<7)],first[maxn],nxt[maxn],to[maxn],val[maxn],tot,c,n,m,d,q,y,ans,vis[maxn];
void add(int u,int v,int w){
	nxt[++tot]=first[u];
	first[u]=tot;
	to[tot]=v;
	val[tot]=w;
}
//struct node{
//	int x,y,d;
//	bool operator<(const node a){
//		return d>a.d;
//	}
//};
//priority_queue<node>g[maxn];
void dfs(int u,int f){
	vis[u]=1;
	for(int i=first[u];i;i=nxt[i]){
		int v=to[i];
		if(vis[v]||v==f||v==u) continue;
		if(v==y) ans+=val[i];
		dfs(v,u);
	}
}
//void djikstra(int s){
//	int k=0;
//	for(int i=1;i<=cnt;i++)
//}
int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		add(3*i,3*i-1,w);
		cnt++;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			memset(a,0,sizeof(a)); 
			int t;
			cin>>a[j]>>t;
			if(j==1){
				add(3*a[j]-1,3*a[j],t);
				cnt++; 
			}
			else{
				add(3*a[j]-1,3*a[j],t);
				add(3*a[j-1],3*a[j],0);
				cnt+=2;
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		ans=0;
		cin>>x>>y;
		dfs(x,0);
		cout<<ans;
	}
	return 0;
}
