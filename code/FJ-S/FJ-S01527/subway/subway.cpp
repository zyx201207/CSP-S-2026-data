#include<bits/stdc++.h>
#define _for(i,a,b) for(int i = (a);i <= (b);i++)
#define int long long

using namespace std;

inline int read();
inline void print(int t);

int c,n,m,d,q;
int w[500005];
int k[505];
struct Node{
	int v;
	int value;
};

vector<Node> mp[500005];

struct P{
	int p,v;
	bool operator <(const P &other) const{
		return v < other.v;
	}
};

int dis[500005];
bool vis[500005];

int Dj(int s,int e){
	_for(i,1,(n + 1) * m){
		dis[i] = 1e18;
	}
	
	memset(vis,false,sizeof vis);
	dis[s] = 0;
	priority_queue<P> q;
	q.push({s,0});
	while(!q.empty()){
		int u = q.top().p;
		int vl = q.top().v;
		q.pop();
		
		vis[u] = true;
		_for(i,0,mp[u].size() - 1){
			int v = mp[u][i].v;
			int d = mp[u][i].value;
			if(vis[v]) continue;
			if(vl + d < dis[v]){
				dis[v] = vl + d;
				q.push({v,dis[v]});
			}
			else{
				q.push({v,vl + d});
			}
		}
		if(vis[e]){
			break;
		}
	}
	return (w[s] + w[e] + dis[e]);
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read();n = read();m = read();d = read();q = read();
	_for(i,1,m){
		w[i] = read();
	}	
	_for(i,1,n){
		k[i] = read();
		_for(j,1,k[i]){
			int a = read(),t = read();
			int u = m * i + j;
			mp[a].push_back({u,t});
			mp[u].push_back({a,t});
		}
		_for(j,2,k[i]){
			int u = m * i + j - 1;
			int v = m * i + j;
			mp[u].push_back({v,0});
			mp[v].push_back({u,0});
		}
	}
	if(c <= 11){
		while(q--){
			int u =read(),v = read();
			print(Dj(u,v));
			putchar('\n');
		}
	}
	
	return 0;
}

inline int read(){
	int x = 0,w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + (ch - 48);
		ch = getchar();
	}
	return x * w;
}

inline void print(int t){
	if(t < 0){
		putchar('-');
		t = -t;
	}
	static int sta[65];
	int top = 0;
	do{
		sta[top++] = t % 10;
		t /= 10;
	}while(t);
	while(top--) putchar(sta[top] + '0');
}
