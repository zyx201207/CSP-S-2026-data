#include<bits/stdc++.h>
#define ll long long
#define fre(s) freopen(s".in" , "r" , stdin) , freopen(s".out" , "w" , stdout)
#define inf (214748364700000000)

using namespace std;

int n , m , q , c , d;

ll a[600005] , num , vis[600005] , dis[600005];

struct node{
	
	ll to , w;
	
};

vector<node>mp[600005];

struct cmp{
	
	ll id , path;
	
	bool operator > (const cmp & oth)const{
	
		return path > oth.path;
		
	}
	
};

priority_queue< cmp , vector<cmp> , greater<cmp> >pq;

int main(){

	fre("subway");
	
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	
	cin >> c >> m >> n >> d >> q;
	
	for(int i = 1 ; i <= n ; i ++)cin >> a[i];
	
	ll u , v , k;
	
	for(int i = 1 ; i <= m ; i ++){
		
		cin >> num;
		
		for(int j = 1 ; j <= num ; j ++){
			
			cin >> u >> k;
			
			mp[u].push_back({n + i , k});
			mp[n + i].push_back({u , k});
			
		}
		
	}
	
	while(q --){
		
		for(int i = 1 ; i <= n + m ; i ++)vis[i] = 0 , dis[i] = inf;
		
		cin >> u >> v;
		
		pq.push({u , 0});
		
		dis[u] = 0;
		
		while(! pq.empty()){
		
			cmp now = pq.top();
			
			pq.pop();
			
			if(vis[now.id])continue;
			vis[now.id] ++;
			
			for(auto i : mp[now.id]){
				
				//cout << i.to << " " << i.w << " ";
				
				if(dis[i.to] > now.path + i.w){
					
					dis[i.to] = now.path + i.w;
					
					pq.push({i.to , dis[i.to]});
					
				}				
				
			}

			
		}	
		
		cout << dis[v] + a[u] + a[v] << "\n";
			
	}
	
	/*for(int i = 1 ; i <= n + m ; i ++){
		for(auto j : mp[i])cout << j.to << " " << j.w << "\n";
		cout << "\n";
	}*/

	return 0;

}

