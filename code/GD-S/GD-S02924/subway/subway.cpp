#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define debug(n) cout << #n << " = " << n << "\n";
#define deb(n) cout << #n << " = " << n << "    ";
#define div() cout << "\n---------------------\n";
inline int read(){
	int sign = 1;char ch = getchar();
	while(!(ch >= '0' && ch <= '9')){
		if(ch == '-'){sign = -sign;}
		ch = getchar();
	}
	int num = 0;
	while(ch >= '0' && ch <= '9'){
		num = 10*num+ch-'0';
		ch = getchar();
	}
	return num*sign;
}
int c,n,m,d,q;
int walk[500005];
int head[1000005],nxt[1000005],val[1000005],to[1000005],tot;
int dis[1000005];bool vis[1000005];int id;
inline void adde(int u,int v,int w){
	++tot;
	to[tot] = v;val[tot] = w;
	nxt[tot] = head[u];
	head[u] = tot;
}
inline void dij(int s,int t){
	fill(dis,dis+id+1,1e9);
	fill(vis,vis+id+1,0);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	q.push({0,s});
	dis[s] = 0;vis[s] = 1;
	while(q.size()){
		int u = q.top().second;q.pop();
		for(int i = head[u];i;i = nxt[i]){
			int v = to[i];int w = val[i];
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				if(!vis[v]){
					vis[v] = 1;
					q.push({dis[v],v});
				}
			}
		}
	}
	cout << dis[t]+walk[s]+walk[t] << "\n";
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read();n = read();m = read();d = read();q = read();
	for(int i = 1;i <= m;i++){walk[i] = read();}
	id = m;
	for(int i = 1;i <= n;i++){
		int k;k = read();
		int v,w;v = read();w = read();
		id++;adde(id,v,w);adde(v,id,w);
		for(int j = 2;j <= k;j++){
			v = read();w = read();
			id++;
			adde(id,v,w);adde(v,id,w);
			adde(id,id-1,0);adde(id-1,id,0);
		}
	}
	while(q--){
		int u,v;u = read();v = read();
		dij(u,v);
	}
	return 0;
}
