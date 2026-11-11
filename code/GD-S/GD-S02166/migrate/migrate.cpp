#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,d,b[N],vis[N];
vector<int> a[N]; 
/*int head[N],cc;
struct{ int v,next; }a[N];
void add(int u,int v){
	a[++cc].v=v;
	a[cc].next=u;
	head[u]=cc;
}*/
void dfs(int u){
	for(int i=0;i<a[u].size();i++){
		int v=a[u].front();
		vis[v]++;
		dfs(v);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) while(a[i].size()) a[i].clear();
		for(int i=1;i<=n;i++){
			cin>>b[i];
			for(int j=1;j<i;j++) if(b[i]-b[j]<=d) a[j].push_back(i); 
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			dfs(i);
			for(int j=1;j<=n;j++)
				if(vis[j]==2) ans++;
		}
		cout<<ans-2<<endl;
	}
	return 0;
}
