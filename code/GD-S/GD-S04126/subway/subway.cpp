#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#ifdef __unix__
#define gc getchar_unlocked
#else
#define gc _getchar_nolock
#endif
int r(){
	int f=1,k=0,c=gc();
	for(;!isdigit(c);c=gc())	if(c == '-')	f = -1;
	for(;isdigit(c);c=gc())		k=k*10+(c&15);
	return f*k;
}
ll c,n,m,D,Q;
ll w[500005];
struct Node{
	ll v,t;
};
vector <Node> lx[505]; // 地铁路线 
vector <Node> st[500005]; // 站台去哪条线 
ll d[500005];
struct Qu{
	ll last_k,v;
};
bool inq[500005];
void spfa(int x){
	deque <Qu > q;
	q.push_back({0,x});
	for(int i=0;i<=m;i++){
		d[i] = 1e17;
		inq[i] = 0;
	}
	d[x] = w[x];
	while(!q.empty()){
		ll last_k = q.front().last_k,u = q.front().v;
		q.pop_front();
		inq[u] = 0;
		for(int i=0;i<st[u].size();i++){
			if(st[u][i].v == last_k)	continue;
			ll nxt_t = st[u][i].t;
			for(int j=0;j<lx[st[u][i].v].size();j++){
				ll v = lx[st[u][i].v][j].v;
				ll t = lx[st[u][i].v][j].t;
				if(d[v] > d[u]+nxt_t+t){
					d[v] = d[u]+nxt_t+t;
					inq[v] = 1;
					q.push_back({st[u][i].v,v});
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	cin >> c >> n >> m >> D >> Q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			ll ai,ti;
			cin >> ai >> ti;
			lx[i].push_back({ai,ti});
			st[ai].push_back({i,ti});
		}
	}
	while(Q--){
		ll x,y;
		cin >> x >> y;
		spfa(x);
		cout << d[y]+w[y] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
