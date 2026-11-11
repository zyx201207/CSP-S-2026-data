#include<bits/stdc++.h>
using namespace std;

int spot[1000100];
int f[1000100];
int flag[1000100];
int dis[1001000];
int find(int x){
	if(f[x] != x){
		return find(f[x]);
		
	}return x;
}
void merge(int x,int y){
	if(f[x] != f[y]){
		f[y] = find(f[x]);
	}
}
int MAXN = 9999990;

int main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
		
//	
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	
	int c,t;
	cin >> c >> t;
	while(t--){
		
		memset(flag,0,sizeof(flag));
		memset(spot,0,sizeof(spot));
		
		
		int n,k;cin >> n>> k;
		for(int i = 0;i <= n;i++){
			f[i] = i;
		}fill(dis,dis+n+10,MAXN);
		vector<int>g[n];
		priority_queue<pair<int,int> >q;
		queue<int>uq;
		for(int i = 1;i < n;i++){
			int u,v;cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
			spot[u]++;
			spot[v]++;
			
		}
		for(int i = 1;i <= n;i++){
			q.push({spot[i],i});
		}
		int block = 0;
		for(int i = 0;i <= k and  !q.empty();){
			
			int v = q.top().first,u = q.top().second;
			q.pop();
			flag[u] = 1;
			int temp = 0;	int q;
			for(int p = 0;p < g[u].size();p++){
			q = g[u][p];
				if(flag[q] == 1){
					f[u] = find(q);dis[u] = 0;
					i++;temp = 1;uq.push(q);
					break;
				}
			}
			if(!temp){
				if(block >= 2){
					flag[u] = 0;
					i--;	
					continue;
				}
				else{
					dis[u] = 0;
					uq.push(q);
					block++;
				}
			}
	
			
		}
		while(!uq.empty()){
			queue<pair<int,int> > oq;
			oq.push({uq.front(),0});
			uq.pop();
			while(!oq.empty()){
				int u1 = oq.front().first,v1 = oq.front().second;
			
				
				for(int j = 0;j < g[u1].size();j++){
					
					dis[g[u1][j]] = min(dis[g[u1][j]],v1+1);	
					oq.push({g[u1][j],	dis[g[u1][j]]+1});
					
				}
				
				
			}

		}
		int ans = 0;
		for(int i = 1;i <= n;i++){
			ans = max(ans,dis[i]);
			
			
		}
		
		cout << ans << endl;
		
		 
		
		
		
		
	} 
	
	
	
	return 0;
} 
