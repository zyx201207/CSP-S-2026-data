#include<bits/stdc++.h>
#define N 105
using namespace std;
int c,T,n,k,p[N],q[N],cur,fa[N];
bitset<N> ok[N],vis,bis;
vector<int> g[N];
void init(int u){
	for(int v : g[u]){
		if(v == fa[u]){
			continue;
		}
		fa[v] = u;
		init(v);
	} 
}
void paint(int u,int dep){
	if(dep < 0 or ok[cur][u] == true){
		return;
	}
	ok[cur][u] = true;
	for(int v : g[u]){
		paint(v,dep - 1);
	}
}
bool check(int y,int j,int cnt){
	if(j == k or y > n){
		for(int x = 1;x <= n;x ++){
			if((vis & ok[q[x]]).count() == 0){
				return false;
			}
		}
		return true;
	}
	if(check(y + 1,j,cnt) == true){
		return true;
	}
	int i = p[y];
	int ncnt = cnt + ((bis[i] | vis[fa[i]]) ^ 1);
	if(ncnt > 2){
		return false;
	}
	bool flag = bis[fa[i]];
	vis[i] = true;
	bis[fa[i]] = true;
	if(check(y + 1,j + 1,ncnt) == true){
		vis[i] = false;
		bis[fa[i]] = flag;
		return true;
	}
	vis[i] = false;
	bis[fa[i]] = flag;
	return false;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	mt19937 rnd(time(0));
	cin >> c >> T;
	while(T --){
		cin >> n >> k;
		for(int i = 1;i <= n;i ++){
			g[i].clear();
			fa[i] = 0;
			p[i] = i;
			q[i] = i;
		}
		for(int i = 1;i < n;i ++){
			int u,v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		init(1);
		int l = 0,r = n,mid = 0,ans = 0;
		while(l <= r){
			int mid = (l + r) >> 1;
			for(int i = 1;i <= n;i ++){
				ok[i].reset();
			}
			for(int i = 1;i <= n;i ++){
				cur = i;
				paint(i,mid);
			}
			shuffle(p + 1,p + n + 1,rnd);
			shuffle(q + 1,q + n + 1,rnd);
			if(check(1,0,0) == true){
				ans = mid;
				r = mid - 1;
			}else{
				l = mid + 1; 
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

