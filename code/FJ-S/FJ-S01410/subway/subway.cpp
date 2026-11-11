#include<bits/stdc++.h>
using namespace std;
const int MAXN = 510,MAXM = 500010;
struct node{
	int id,time;
}mp[MAXM][21];
struct node2{
	int v;
	long long dis;
	bool operator <(const node2 &x)const{
		return dis > x.dis;
	}
};
int c,n,m,d,q,u,v,tmp1,tmp2,w[MAXM],k[MAXN],top[MAXM];
long long dist[MAXN][MAXN];
bitset<MAXN> vis[MAXN];
vector<node> edge[MAXN];
priority_queue<node2> pq;
void dijkstra(int s){
	pq.push({s,0});
	dist[s][s] = 0;
	while(!pq.empty()){
		node2 u = pq.top();
		pq.pop();
		int x = u.v;
		if(vis[s][x]) continue;
		vis[s][x] = 1;
		for(int i = 0;i<(int)edge[x].size();i++){
			int to = edge[x][i].id;
			long long w1 = edge[x][i].time;
			for(int j = 1;j<=top[to];j++){
				int id = mp[to][j].id,w2 = mp[to][j].time;
				long long cnt = dist[s][x]+w1+w2;
				if(dist[s][id]>cnt){
					dist[s][id] = cnt;
					if(!vis[s][id]) pq.push({id,cnt});
				}
			}
		}
	}
}
long long read(){
	int f = 1;
	long long b = 0;
	char ch = _getchar_nolock();
	while(ch<'0' || ch>'9') f = -1,ch = _getchar_nolock();
	while(ch>='0' && ch<='9') b = b*10+(ch-'0'),ch = _getchar_nolock();
	return f*b;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read();n = read();m = read();d = read();q = read();
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n;j++)
			dist[i][j] = 1e18;
	for(int i = 1;i<=m;i++) w[i] = read();
	for(int i = 1;i<=n;i++){
		k[i] = read();
		for(int j = 1;j<=k[i];j++){
			tmp1 = read();tmp2 = read();
			edge[i].push_back({tmp1,tmp2});
			mp[tmp1][++top[tmp1]] = {i,tmp2};
		}
	}
	for(int i = 1;i<=n;i++) dijkstra(i);
	while(q--){
		u = read();v = read();
		long long minn = 1e18;
		for(int i = 1;i<=top[u];i++){
			for(int j = 1;j<=top[v];j++){
				int ss = mp[u][i].id,ee = mp[v][j].id,my = mp[u][i].time,my2 = mp[v][j].time;
				minn = min(minn,my+my2+dist[ss][ee]);
			}
		}
		printf("%lld\n",minn+w[u]+w[v]);
	}
	return 0;
}
