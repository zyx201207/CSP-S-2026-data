#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 5e4+1;
ll c,n,m,d,q,k[N];
ll w[N],a[510][N],t[510][N];
ll dist[N];
bool vis[N];
int ans;
struct test{
	ll f,s;
	bool operator < (const test &o) const {
		return f > o.f;
	}
};
struct node{
	ll f,cnt;
};
vector<ll> op[N];
vector<test> e[N];
void bfs(int start,int end){
	queue<node> q;
	q.push({start,1});
	while(!q.empty()){
		int u = q.front().f;
		int ncnt = q.front().cnt;q.pop();
		vis[u] = 1;
		if(u==end){
			ans = ncnt;
			break;
		}
		for(auto nop:op[u]){
			for(int i = 1;i <= k[nop];i++){
				if(vis[a[nop][i]])continue;
				q.push({a[nop][i],ncnt+1});
			}
		}
	}
}
void dj(int start){
	priority_queue<test>pq;
	dist[start] = 0;
	pq.push({0,start});
	while(!pq.empty()){
		int u = pq.top().s;
		int w = pq.top().f;pq.pop();
		if(vis[u])continue;
		vis[u] = 1;
		for(int i = 0;i < e[u].size();i++){
			//cout <<"&";
			int vv = e[u][i].f;
			int vw = e[u][i].s;
			if(dist[u]+vw < dist[vv]){
				dist[vv] = dist[u]+vw;
				//cout <<"*";
				pq.push({dist[vv],vv});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++){
		cin >>w[i];
	}
	if(c >= 0 && c <= 11){
		for(int i = 1;i <= n;i++){
			cin >>k[i];
			for(int j = 1;j <= k[i];j++){
				cin >>a[i][j]>>t[i][j];
			}
			for(int j = 1;j <= k[i];j++){
				for(int s = j+1;s <= k[i];s++){	
					ll idx = t[i][j]+t[i][s];
					e[a[i][j]].push_back({a[i][s],idx});
					//cout <<"^";
					e[a[i][s]].push_back({a[i][j],idx});
				}
			}
		}
		for(int i = 1;i <= q;i++){
			int xa,ay;cin >>xa>>ay;
			memset(dist,0x3f,sizeof(dist));
			memset(vis,0,sizeof(vis));
			dj(xa);
			//cout <<dist[ay]<<" ";
			cout <<dist[ay]+w[xa]+w[ay]<<endl;
		}
	}
	if(c >= 12&&c <= 19){
		int tt;
		for(ll i = 1;i <= n;i++){
			cin >>k[i];
			for(ll j = 1;j <= k[i];j++){
				cin >>a[i][j]>>t[i][j];
				tt = t[i][j];
				op[a[i][j]].push_back(i);
			}
		}
		for(int i = 1;i <= q;i++){
			int x,y;cin >>x>>y;
			bfs(x,y);
			cout <<w[x]+w[y]+ans*tt<<endl;
		}
	}	
	return 0;
}
