#include<bits/stdc++.h>
using namespace std;
const int N=15;
int c,t;
int n,k,cnt,ans;
int fa[N];
int xz[N],pic[N][N],bk[N],vis[N];
void dfs(int );
int ccc(int );
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=n;
		cin>>n>>k;
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			pic[u][v]=pic[v][u]=1;
		}
		dfs(0);
		cout<<(n-k)/2<<"\n";
	}
}
void dfs(int t){
	if(t==k){
		cnt=0;
		for(int i=1;i<=t;i++){
			for(int j=1;j<=t;j++){
				if(i==j) continue;
				if(pic[xz[i]][xz[j]]) fa[find(xz[i])]=find(xz[j]);
			}
		}
		for(int i=1;i<=t;i++){
			if(fa[xz[i]]==xz[i]) cnt++;
		}
		if(cnt>2) return;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				vis[j]=0;
			}
			if(!bk[i]) ans=min(ans,ccc(i));
		}
	}
	else{
		for(int i=xz[t]+1;i<=n-t;i++){
			xz[t+1]=i;
			dfs(t+1);
		}
	}
	return ;
}
int ccc(int x){
//	cerr<<"sii\n";
	vis[x]=1;
	queue<pair<int,int > > q;
	while(!q.empty()) q.pop();
	q.push(make_pair(x,0));
	while(!q.empty()){
		int u=q.front().first;
		vis[u]=1;
		int w=q.front().second;q.pop();
		for(int i=1;i<=n;i++){
			if(!pic[u][i]||vis[i]) continue;
			if(bk[k]) return w+1;
			else q.push(make_pair(i,w+1));
		}
	}
	return n;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
