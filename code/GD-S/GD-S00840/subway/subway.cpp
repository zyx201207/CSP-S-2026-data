#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
const int N = 5e5 + 9;
const ll inf = 2e16;
const ll NEG = -2e15;
const ll mod = 1e9 + 7;
ll w[N];
ll dis[509][509];
ll t[509][509];
vector<int>line[509];
vector<int>to[N];
map<int,ll> point[N];

vector<ll> Jid(int x,int n){
	priority_queue<pli,vector<pli>,greater<pli> >q;
	vector<ll>ds(n+1,inf);
	q.push({0,x});
	ds[x] = 0;
	while(!q.empty()){
		pli r = q.top();
		q.pop();
		int u = r.second,d = r.first;
		
		if(ds[u] < d) continue;
		
		for(int i = 1;i <= n;i++){
			if(u != i && ds[i] > d + dis[u][i]){
				ds[i] = d + dis[u][i];
				q.push({ds[i],i});
			}
		}
	}
	return ds;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i = 1;i <= n;i++){
		int k;
		scanf("%lld",&k);
		for(int j = 1;j <= k;j++){
			int x,t;
			scanf("%lld %lld",&x,&t);
			line[i].push_back(x);
			to[x].push_back(i);
			point[x][i] = t;
		}
	}
	
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if(i == j) dis[i][i] = 0,t[i][i] = 0;
			else dis[i][j] = dis[j][i] = inf,t[i][j] = t[j][i] = inf;
		} 
	}
	
	
	for(int i = 1;i <= n;i++){
		for(auto x : line[i]){
			for(auto j : to[x]){
				if(i == j) continue;
				dis[i][j] = dis[j][i] = min(dis[i][j],point[x][i] + point[x][j]);
//				cout << i << ' ' << j << ' ' << dis[i][j] << '\n';
			}
		}
//		cout << '\n';
	}
	
	
	for(int i = 1;i <= n;i++){
		vector<ll> nxt = Jid(i,n);
		for(int j = 1;j <= n;j++){
			t[i][j] = t[j][i] = min(t[i][j],nxt[j]);
		}
	}
	
	
	while(q--){
		int x,y;
		scanf("%lld %lld",&x,&y);
		ll ans = w[x] + w[y];
		ll nxt = inf;
		for(int i = 0;i < (int)to[x].size();i++){
			for(int j = 0;j < (int)to[y].size();j++){
				int l1 = to[x][i],l2 = to[y][j];
				nxt = min(nxt,point[x][l1] + t[l1][l2] + point[y][l2]);
			}
		}
		printf("%lld\n",ans+nxt);
	}
	
	return 0;
}

