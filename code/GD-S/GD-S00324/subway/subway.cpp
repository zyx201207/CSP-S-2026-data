#include<bits/stdc++.h>
using namespace std;
const long long inf=2e18;
const int N=2e6+5;
int cv,n,m,d,q;
int h[N],nxt[N],to[N],c,col[N];
int w[N];
int k[N];
int last,now,tt;
int x,y;
long long dis[N];
vector<int> t[N];
void add(int u,int v,int cl){
	nxt[++c]=h[u];
	h[u]=c;
	to[c]=v;
	col[c]=cl;
}
struct node{
	int dis,id,c;
	bool  operator > (node a,node b){
		return a.dis<b.dis;
	}
};
priority_queue<node> q;
void dijistra(){
	for(int i=1;i<=m;i++){
		dis[i]=inf;
	}
	dis[x]=0;node v={0,x,-1};q.push(v);
	while(!q.empty()){
		node u=q.top();q.pop();
		if(vis[u.id])continue;
		vis[u.id]=1;
		for(int i=h[u.id];i;i=nxt[i]){
			if(u.c==col[i]){
				if(dis[to[i]]>dis[u]){
					dis[to[i]]=dis[u];
					q.push({dis[to[i]],to[i],u.c});
				}
			}else{
				if(dis[to[i]]>dis[u]+t[u][col[c]])+t[to[i]][col[c]]){
					dis[to[i]]=dis[u]+t[u][col[c]])+t[to[i]][col[c]];
					q.push({dis[to[i]],to[i],col[c]});
				}
			}
		}
	}
	return;
}
long long ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		cin>>last>>tt;
		t[now].push_back(tt);
		for(int j=1;j<=k[i];j++){
			cin>>now>>tt;
			t[now].push_back(tt);
			add(last,now,i);
		}
	}
	while(q--){
		cin>>x>>y;
		ans+=w[x]+w[y];
		dijistra();
		ans+=dis[y];
		cout<<ans;
	}
	return 0;
}
