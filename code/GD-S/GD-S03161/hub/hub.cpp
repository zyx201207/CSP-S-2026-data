#include<bits/stdc++.h>
#define qpii queue<pair<int,int>>
using namespace std;
const int N=1e7;
int n,k,had[N],cnt=0,vis[N];
struct node{int to,nxt;} edg[N+N];
void add(int u,int v){
	edg[cnt].to=v;
	edg[cnt].nxt=had[u];
	had[u]=cnt++;
}
int chk(qpii q){
	memset(vis,0,sizeof(vis));
	int t=0,c=q.size();
	bool tp=0;
	while(!q.empty()){
		int sz=q.size();
		bool f=0;
		for(int j=0;j<sz;j++){
			auto p=q.front();
			q.pop();
			int u=p.first;
			for(int i=had[u];i!=-1;i=edg[i].nxt){
				int v=edg[i].to;
				if(!vis[v]){
					q.push({v,p.second+1}),
					vis[v]=1,c++;
					if(c==k) f=1;
					if(tp) t=max(t,p.second+1);
				}
			}
		}
		if(f){
			tp=1,sz=q.size();
			for(int i=0;i<sz;i++){
				q.front().second=0;
				q.push(q.front());
				q.pop();
			}
		}
	}
	return t;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(had,-1,sizeof(had));
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		int t=0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			t=min(t,1+chk(qpii({{i,0}})));
			for(int j=i+1;j<=n;j++)
				t=min(t,1+chk(qpii({{1,0},{j,0}})));
		}
		cout<<t<<endl;
	}
	return 0;
}
