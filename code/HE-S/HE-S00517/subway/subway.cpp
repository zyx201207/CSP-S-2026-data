#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

typedef long long LL;
typedef pair<LL,int> PII; 


LL d[1510][1510];
bool st[1510][1510]; 

int C,n,m,D,T;

vector<PII> e[N];
LL a[N];
int uid;

void dj(int s){
	priority_queue<PII,vector<PII>,greater<PII> > heap;
	d[s][s] = 0;
	heap.push({0,s});
	while(heap.size()){
		int u = heap.top().second;
		heap.pop();
		if(st[s][u]) continue;
		st[s][u] = 1;
		for(int i = 0;i < e[u].size();i++){
			int u1 = e[u][i].second,dist = e[u][i].first + d[s][u];
			if(d[s][u1] > dist){
				d[s][u1] = dist;
				heap.push({dist,u1});
			} 
		}
	}
} 

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>D>>T;
	uid = m;
	for(int i = 1;i <= m;i++) cin>>a[i];
	for(int i = 1;i <= n;i++){
		uid++;
		int k;
		cin>>k;
		for(int i = 1;i <= k;i++){
			int x,y;
			cin>>x>>y;
			e[uid].push_back({y,x});
			e[x].push_back({y,uid});
		}
	}
	memset(d,0x3f,sizeof d);
	for(int i = 1;i <= m;i++) dj(i);
	while(T--){
		int x,y;
		cin>>x>>y;
		cout<<d[x][y] + a[x] + a[y]<<'\n';
	}
	return 0;
} 
