#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e3 + 5;

vector<int> t[N];

bool vis[N];
bool cho[N];

int n,k;
int dist[N];

struct stu{
	int v;
	int w;
};

void lian(int u,int fa){
	
	if(cho[u] == 0) return ;
	
	if(vis[u] == 1) return ;
	vis[u] = 1;
	
	for(int i = 0; i < t[u].size(); i++){
		if(t[u][i] == fa) continue;
		lian(t[u][i],u);
	}
}

int bfs( ){
	
	for(int i = 1; i <= n; i++){
		vis[i] = 0;
	}
	
	int num = 0;
	for(int i = 1; i <= n; i++){
		if(vis[i] == 0 && cho[i] == 1){
			
			lian(i,0);
			num++;
			
			if(num >= 3){
				return 10000;
			}
		}
	}
	
	queue<stu> q;
	for(int i = 1; i <= n; i++){
		vis[i] = 0;
		if(cho[i] == 1){
			q.push({i,0});
			vis[i] = 1;
		}
	}
	
	int nownum = 0;
	while(!q.empty()){
		stu now = q.front();
		q.pop();
		
		int u = now.v;
		
		vis[u] = 1;

		for(int i = 0; i < t[u].size(); i++){
			int v = t[u][i];
			
			if(vis[v] == 0){
				//cout << "???";
				nownum = max(nownum , now.w+1);
				q.push({v,now.w+1});
			}
		}
	}
	return nownum;
}

int ans = 1e8;
void dfs(int ii,int now){
	if(now > k){
		ans = min(ans , bfs());
		return ;
	}
	
	for(int i = ii+1; i <= n; i++){
		cho[i] = 1;
		dfs(i,now+1);
		cho[i] = 0;
	}
}

int main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int c,ttt;
	cin >> c >> ttt;
	
	while(ttt--){

		cin >> n >> k;
		
		for(int i = 1; i <= n; i++){
			cho[i] = 0;
		}
		
		for(int i = 1; i < n; i++){
			int u,v;
			cin >> u >> v;
			
			t[u].push_back(v);
			t[v].push_back(u);
		}
		
		dfs(0,1);
		
		cout << ans << '\n';
	}
	
	return 0;
}
