#include<bits/stdc++.h>
using namespace std;
int zt[1000005],dtk[1000005];
int h[2000006],nxt[2000006],v[2000006],to[2000006],cnt;
void add(int a,int b,int c){
	to[++cnt]=b;
	v[cnt]=c;
	nxt[cnt]=h[a];
	h[a]=cnt;
}
int p;
priority_queue<pair<int,int> >q;
bool vis[2000006];
int dis[1000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,qq,w,a,t;
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;++i){
		cin>>w;
		++p;dtk[i]=p;
		++p;zt[i]=p;
		add(dtk[i],zt[i],w);
		add(zt[i],dtk[i],w);
	}
	int kk;
	for(int i=1;i<=n;++i){
		cin>>kk;
		++p;
		for(int j=1;j<=kk;++j){
			cin>>a>>t;
			add(p,zt[a],t);
			add(zt[a],p,t);
		}
	}
	while(qq--){
		int x,y;cin>>x>>y;
		while(!q.empty())q.pop();
		q.push(make_pair(0,dtk[x]));
		for(int i=1;i<=p;++i)vis[i]=0,dis[i]=1e9;
		dis[dtk[x]]=0;
		while(!q.empty()){
			int u=q.top().second;
			q.pop();
			if(vis[u])continue;
			vis[u]=1;
			for(int i=h[u];i;i=nxt[i]){
				int vv=to[i];
				if(vis[vv])continue;
				if(dis[vv]>dis[u]+v[i]){
					dis[vv]=dis[u]+v[i];
				}
				q.push(make_pair(-dis[vv],vv));
			}
		}
		cout<<dis[dtk[y]]<<endl;
	}
	return 0;
}
