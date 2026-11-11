#include<bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, w[515414], k, a[514514], t[514514], dis[514514], vis[514514];
struct pos{
       long long v, w;
       bool operator <(const pos &x)const{
           return x.w<w;
       }
};
vector <pos> g[514514];
void dij(int s){
	priority_queue <pos> p;
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	dis[s]=0;
	p.push({s, 0});
	while(!p.empty()){
		pos to=p.top();
		p.pop();
		int u=to.v;
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			pos os=g[u][i];
			int v=os.v, w=os.w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				p.push({v, dis[v]});
		     }
		}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
   cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
            g[i].push_back({a[j]+1145, t[j]});
            g[a[j]+1145].push_back({i, t[j]});
        }
    }
    while(q--){
		int s, t;
		cin>>s>>t;
	   dij(s+1145);
	    cout<<w[s]+w[t]+dis[t+1145]<<"\n";
	} 
    return 0;
}
