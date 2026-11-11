#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
vector<int> g[1000005];
int dist[15][15];
bool f[15],vis[15];
void bfs(int i){
	queue<int> q;
	q.push(i);
	dist[i][i]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:g[u]){
			if(dist[i][v]!=0x3f3f3f3f)continue;
			dist[i][v]=dist[i][u]+1;
			q.push(v);
		}
	}
}
void bfs2(int i){
	queue<int> q;
	q.push(i);
	vis[i]=true;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:g[u]){
			if(vis[v]||(!f[v]))continue;
			vis[v]=true;
			q.push(v);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(c<=3){
			memset(dist,0x3f,sizeof dist);
			for(int i=1;i<=n;i++)bfs(i);
			int final_ans=1e9;
			for(int mask=0;mask<(1<<n);mask++){
				memset(f,0,sizeof f);
				memset(vis,0,sizeof vis);
				int cnt=0;
				vector<int> p;
				int num=0;
				for(int i=1;i<=n;i++){
					if((mask&(1<<(i-1)))==0)continue;
					f[i]=true;
					p.push_back(i);
					num++;
				}
				if(num!=k)continue;
				bool ok=true;
				for(int i=1;i<=n;i++){
					if(f[i]&&!vis[i]){
						if(cnt>=2){
							ok=false;
							break;
						}
						bfs2(i);
						cnt++;
					}
				}
				if(ok==0)continue;
				int ans=0;
				for(int i=1;i<=n;i++){
					int res=1e9;
					for(int j:p){
						res=min(res,dist[i][j]);
					}
					ans=max(ans,res);
				}
				final_ans=min(final_ans,ans);
			}
			cout<<final_ans<<'\n';
		}else if(c>=13&&c<=14){
			if(k==n)cout<<"0\n";
			else if(k>=(n/2))cout<<"1\n";
			else if((n/2-k)%2==0)cout<<(n/2-k)/4+1<<'\n';
			else cout<<(n/2-k+3)/4+1<<'\n';
		}
	} 
	return 0;
}
