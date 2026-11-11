#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5010;
int t,n,vis[N];
ll d,a[N],dis[N],p[N],cnt[N];
int in[N];
vector<int >e[N];
void bfs(int s){
	queue<int>q;
	q.push(s);
	vis[s]=1;
	dis[s]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int y:e[u]){
			if(!vis[y]){
				vis[y]=1;
				dis[y]=dis[u]+1;
				q.push(y);	
			}
			
		}
	}
	
}
void dfs(int u,int w){
	if(w==dis[u]){
		cnt[u]++;
	}
	for(int y:e[u]){
		dfs(y,w+1);
	}
}

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				e[i].push_back(j);
				in[j]++;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		bfs(i);
		dis[i]=-1;
		dfs(i,0);
		for(int j=1;j<=n;j++){
			if(cnt[j]==2){
				ans++;
			}
		}
		memset(dis,0,sizeof(dis));
		memset(vis,0,sizeof(vis));
		memset(p,0,sizeof(p));
		memset(cnt,0,sizeof(cnt));
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		e[i].clear();
	}
	memset(dis,0,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(p,0,sizeof(p));
	memset(cnt,0,sizeof(cnt));
	memset(in,0,sizeof(in)); 
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
   	cout.tie(0);
	int c;
    cin>>c>>t;
    while(t--){
    	solve();
	}
    return 0;
}
/*
4 2
1 2 3 4

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
