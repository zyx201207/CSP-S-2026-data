#include <cstdio>
#include <vector>
#include <queue>
#define ll long long
const int N = 1e6 + 5;
using namespace std;

struct edge{
	int to,nxt;
};

int c,t;
int n,k;
int u,v;

int tot,mxDep,root,tail,ans;
int head[N],dep[N];
edge e[N << 1];
queue<int> que;
vector<int> path;

void add(const int& x,const int& y){
	tot++;
	e[tot].nxt = head[x];
	e[tot].to = y;
	head[x] = tot;
	return;
}

bool calp(const int& x,const int& par){
	if(x == tail){
		path.push_back(x);
		return true;
	}
	for(int id = head[x],y;~id;id = e[id].nxt){
		y = e[id].to;
		if(y == par) continue;
		if(calp(y,x)){
			path.push_back(x);
			return true;
		}
	}
	return false;
}

void dfs(const int& x,const int& par,const int& d,const int& need,int& cnt,int& sum){
	for(int id = head[x],y;~id;id = e[id].nxt){
		y = e[id].to;
		if(y == par) continue;
		else if(cnt == 2 && d == need){
			sum += d + 1;
			dfs(y,x,0,need,cnt,sum);
		}
		else if(d == need){
			cnt++;
			sum++;
			dfs(y,x,0,need,cnt,sum);
		}
		else dfs(y,x,d + 1,need,cnt,sum);
	}
	return;
}

bool check(const int& tar){
	int newRoot = path[tar];
	int cnt,sum;
	cnt = sum = 1;
	dfs(newRoot,0,0,tar,cnt,sum);
	return sum <= k;
}

void solve(){
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i++) head[i] = -1;
	path.clear();
	tot = -1;
	for(int i = 1;i < n;i++){
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	for(int i = 1;i <= n;i++) dep[i] = 0;
	dep[1] = 1;
	que.push(1);
	root = 0;
	while(!que.empty()){
		int x = que.front(); que.pop();
		if(dep[x] > mxDep){
			mxDep = dep[x];
			root = x;
		}
		for(int id = head[x],y;~id;id = e[id].nxt){
			y = e[id].to;
			if(dep[y]) continue;
			dep[y] = dep[x] + 1;
			que.push(y);
		}
	}
	for(int i = 1;i <= n;i++) dep[i] = 0;
	dep[root] = 1;
	que.push(root);
	tail = 0;
	while(!que.empty()){
		int x = que.front(); que.pop();
		if(dep[x] > dep[tail]) tail = x;
		for(int id = head[x],y;~id;id = e[id].nxt){
			y = e[id].to;
			if(dep[y]) continue;
			dep[y] = dep[x] + 1;
			que.push(y);
		}
	}
	calp(root,0);
	int l,r,mid;
	l = 1;
	r = mxDep;
	while(l <= r){
		mid = l + ((r - l) >> 1);
		if(check(mid)){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	printf("%d\n",ans);
	return;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--) solve();
	return 0;
}

