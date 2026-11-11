#include<bits/stdc++.h>
using namespace std;
const int M = 5e5+10;
const int N = 505;
typedef long long ll;
int c,n,m,d,q;
int w[M];
vector<int> a[N],t[N];
vector<pair<int,int> >sub[M];
int k[N],mo[N];
ll sum[M];
int ed[M];
#define pii pair<int,int>
#define fi first
#define se second

//void dfs1(int u,int fa){
//	
//}
//
//void work1(){
//	
//	while(q--){
//		
//	}
//}

struct KK{
	int x,y;
}p[M];
struct Node{
	int station;
	ll len;
	int idx,pos;
	friend bool operator <(Node x,Node y){
		if(x.station == y.station){
			return x.len < y.len;
		}
		else{
			return x.station > y.station;
		}
	}
};

void bfs(int st){
	priority_queue<Node> pq;
	for(int i = 0;i<sub[st].size();i++){
		pq.push((Node{st,0,sub[st][i].fi,0}));
		ed[a[sub[st][i].fi][sub[st][i].se]] = t[sub[st][i].fi][sub[st][i].se];
//		cout<<1;
	}
	while(!pq.empty()){
		Node tmp = pq.top();
		pq.pop();
//		cout<<1;
//		cout<<tmp.station <<' '<< tmp.len<<' '<<tmp.len<<'\n';
//		if(tmp.len > sum[tmp.station]) continue;
		for(int it = 0;it<sub[tmp.station].size();it++){
			int v = sub[tmp.station][it].fi;
			int pos = sub[tmp.station][it].se;
			if(v==tmp.idx)continue;
			if(k[v] > pos+1){
				if(sum[a[v][pos+1]] > tmp.len + t[v][pos] + t[v][pos+1]){
					sum[a[v][pos+1]] = tmp.len + t[v][pos] + t[v][pos+1];
					pq.push((Node){a[v][pos+1],sum[a[v][pos+1]],v,pos+1});
					ed[a[v][pos]] = min(ed[a[v][pos]],t[v][pos+1]);
				}
			}
		}
		if(k[tmp.idx] > tmp.pos+1 && tmp.pos!=0) {
			if(tmp.len - t[tmp.idx][tmp.pos] + t[tmp.idx][tmp.pos+1] < sum[a[tmp.idx][tmp.pos+1]]){
				sum[a[tmp.idx][tmp.pos+1]] = tmp.len - t[tmp.idx][tmp.pos] + t[tmp.idx][tmp.pos+1];
				pq.push({a[tmp.idx][tmp.pos+1],sum[a[tmp.idx][tmp.pos+1]],tmp.idx,tmp.pos+1});
//				cout<<a[tmp.idx][tmp.pos+1]<<' '<<tmp.len<<'\n';
				ed[a[tmp.idx][tmp.pos]] = min(ed[a[tmp.idx][tmp.pos]],t[tmp.idx][tmp.pos+1]);
//				cout<<111<<'\n';
			}
		}
		else if(k[tmp.idx] > tmp.pos+1 && tmp.pos==0) {
			if(tmp.len + t[tmp.idx][tmp.pos+1] < sum[a[tmp.idx][tmp.pos+1]]){
				sum[a[tmp.idx][tmp.pos+1]] = tmp.len + t[tmp.idx][tmp.pos+1];
				pq.push({a[tmp.idx][tmp.pos+1],tmp.len + t[tmp.idx][tmp.pos+1],tmp.idx,tmp.pos+1});
//				cout<<a[tmp.idx][tmp.pos+1]<<' '<<tmp.len<<'\n';
				ed[a[tmp.idx][tmp.pos]] = min(ed[a[tmp.idx][tmp.pos]],t[tmp.idx][tmp.pos+1]);
			}
		}
	}
}

int st=1e8;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=m;i++){
		cin >> w[i];
		sum[i]=1e18;
		ed[i] = 1e9;
	}
	for(int i= 1;i<=n;i++){
		cin >> k[i];
		int x,y;
		for(int j = 1;j<=k[i];++j){
			cin >> p[j].x >> p[j].y;
		}
		sort(p+1,p+k[i]+1,[](KK aa,KK bb){
			return aa.x<bb.x;
		});
		for(int j = 1;j<=k[i];j++){
			x=p[j].x;
			y=p[j].y;
			a[i].push_back(x);
			t[i].push_back(y);
			sub[x].push_back({i,j-1});
		}
		st = min(a[i][0],st);
		mo[i] = x;
	}
	sum[st]=0;
	bfs(st);
	
//	for(int i = 1;i<=m;i++){
//		cout<<sum[i]<<' ';
//	}cout<<'\n';
	while(q--){
		int s,e;
		cin >> s >> e;
		cout<<sum[e]-sum[s]+w[s]+w[e]+(s==1?+ed[s]:0)<<'\n';
	}
}
