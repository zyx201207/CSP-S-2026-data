#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

const int N = 5e5 + 10;

int C,T;

vector<int> e[N];

int d[N],d1[N];
PII f[N];

void dfs(int u,int fa){
	d1[u] = 0;
	f[u] = {d[u] - 1,fa};
	for(int i = 0 ;i < e[u].size();i++){
		int u1 = e[u][i];
		if(u1 == fa) continue;
		d[u1] = d[u] + 1;	
		dfs(u1,u);
		d1[u] = max(d1[u],d1[u1] + 1);
		f[u] = max(f[u],{d1[u1],u1});
	}
}

bool st[N];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--){
		int n;
		int ans = 1e9;
		int m;
		cin>>n>>m;
		d[1] = 1;
		for(int i = 1;i <= n;i++) e[i].clear();
		for(int i = 1;i < n;i++) {
			int x,y;
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		dfs(1,-1);
		
//		for(int i = 1;i <= n;i++) cout<<f[i].second<<' ';
//		cout<<'\n'; 
		
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i == j) continue;
				priority_queue<PII> heap; 
				heap.push(f[i]);
				heap.push(f[j]);
				for(int l = 1;l <= n;l++) st[l] = 0;
				int u = m;
				//puts("-------");
				while(u&&heap.size()){
					//cout<<11111111<<'\n';
					int u1 = heap.top().second;
					heap.pop();
					//cout<<u1<<'\n';
					//cout<<heap.size()<<'\n'; 
					if(st[u1]) continue;
					st[u1] = 1;
					u --;
					for(int l = 0;l < e[u1].size();l++){
						int u2 = e[u1][l];
						heap.push(f[u2]);
					}
				}
				
//				cout<<n<<'\n';
//				for(int i = 1;i <= n;i++) if(st[i]) cout<<i<<'\n';
				while(heap.size()){
					int u1 = heap.top().second;
					if(st[u1]) heap.pop();
					else break; 
				} 
				//if(heap.size() == 0) puts("11111111111111");
//				cout<<heap.top().second<<' '<<heap.top().first<<'\n';
				if(heap.size() == 0) ans = 0;
				else ans = min(ans,heap.top().first);
				
			}
		}
		cout<<ans<<"\n";
	}
	
	
	
	return 0;
} 
