#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,cnt,ans;
struct edge{
	int to,nxt;
}g[605];
int head[300];
void add(int u,int v){
	g[++cnt].to=v;
	g[cnt].nxt=head[u];
	head[u]=cnt;
}
int vis[20];
queue<pair<int,int> >q;
int bfs(int s,int p){
	memset(vis,0,sizeof(vis));
	while(!q.empty()) q.pop();
	q.push({s,0});
	vis[s]=1;
	int u,w;
	while(!q.empty()){
		u=q.front().first,w=q.front().second;
		q.pop();
//		if((!t)&&p==262) cerr<<s<<" "<<u<<" "<<w<<" "<<(p&(1<<(u-1)))<<"\n";
		if(p&(1<<(u-1))) return w;
		for(int i=head[u],v;i;i=g[i].nxt){
			v=g[i].to;
			if(vis[v]) continue;
			vis[v]=1;
			q.push({v,w+1});
		}
//		cerr<<p<<" "<<s<<" "<<u<<" "<<w<<"\n";
	} 
	return 0;
}
int res(int s){
	int ret=1;
	for(int i=1;i<=n;i++)
		ret=max(ret,bfs(i,s));
	return ret;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;cnt=0;
		memset(head,0,sizeof(head));
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		if(k==n){
			cout<<0<<"\n";
			continue;
		}
		if(k==n-1){
			cout<<1<<"\n";
			continue; 
		}
		if(c<=1){
			ans=1e9;
			for(int s=0,pq;s<(1<<n);s++){
				pq=0;
				for(int j=0;j<n;j++)
					if(s&(1<<j)) pq++;
				if(pq==k){
					pq=res(s);
			//		cerr<<s<<" "<<pq<<"\n";
					ans=min(ans,pq);
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		cout<<1<<"\n";
	}
	return 0;
}

