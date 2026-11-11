#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;

int n; ll d , a[2000005];

namespace baoli {
	pair <int , int> dis[5005]; bool vis[5005];
	
	inline void bfs(int st){
		queue <int> q; q.push(st);
		memset(vis , 0 , sizeof(vis));
		for(int i = 1;i <= n;i++) dis[i] = {114514 , 0};
		dis[st] = {0 , 1}; vis[st] = 1;
		while(!q.empty()){
			int t = q.front(); q.pop();
			int nxt = t + 1;
			while(nxt <= n && a[nxt] - a[t] <= d){
				if(dis[nxt].first > dis[t].first + 1){
					dis[nxt].first = dis[t].first + 1;
					dis[nxt].second = dis[t].second;
					if(!vis[nxt]){
						q.push(nxt);
						vis[nxt] = 1;
					} 
				}
				else if(dis[nxt].first == dis[t].first + 1)
					dis[nxt].second += dis[t].second;
				nxt++;
			}
		}
	}
	
	inline void solve(){
		ll ans = 0;
		for(int i = 1;i <= n;i++){
			bfs(i);
			for(int j = i + 1;j <= n;j++)
				ans += (dis[j].second == 2);
		}
		printf("%lld\n" , ans);
	}
}

namespace baobao {
	int f[2005];
	int tot = 0;
	
	void dfs(int x , int y , int p){
		if(tot > 3 || p < 0) return ;
		if(x == y){ tot++; return ; }
		int i = x + 1;
		while(i <= y && a[i] - a[x] <= d){
			dfs(i , y , p - 1);
			i++;
		}
	}
	
	void solve(){
		ll ans = 0;
		for(int i = 1;i <= n;i++){
			int z = i;
			f[i] = 0;
			for(int j = i + 1;j <= n;j++){
				while(a[j] - a[z] > d) z++;
				f[j] = f[z] + 1;
				tot = 0; dfs(i , j , f[j]);
				ans += (tot == 2);
//				if(tot == 2) printf("%d %d\n" , i , j); 
			}
		}
		
		printf("%lld\n" , ans);
	}
}

namespace wssb {
	int f[2000005] , lt[2000005] , g[2000005];
	void solve(){
		for(int i = 1 , j = 1;i <= n;i++){
			while(a[i] - a[j] > d) j++;
			lt[i] = j;
		}
		for(int i = n , j = n;i >= 1;i--){
			while(a[j] - a[i] > d) j--;
			if(i == j) g[i] = 1;
			else if(j == i + 1) g[i] = g[j] + 1;
		}
		ll ans = 0;
		for(int i = 1;i <= n;i++){
			int j = lt[i];
			f[i] = 1;
			if(j != i) f[i] += f[j];
			
			if(j + 1 >= i) continue;
			
			int z = j - 1;
			if(j + 2 < i) z = lt[j + 2] - 1;
			int tmp = z , qwq = -1;
//			printf("z1 %d\n" , z);
			ll ad = 0;
			while(z >= 1 && a[j + 1] - a[z] <= d){
				if(lt[z] != qwq){
					ad += f[z];
					qwq = lt[z];
				}
				else ans++;
				ad -= tmp - z;
				z--;
			}
//			printf("z2 %d\n" , z);
			while(z >= 1 && a[j] - a[z] <= d){
				ad -= tmp - z;
				z--;
			}
//			printf("z3 %d\n" , z);
			ans += ad * g[i];
//			printf("%d:%lld %d\n" , i , ad * g[i] , f[i]);
		}
		printf("%lld\n" , ans);
	}	
}

int main(void){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
//	freopen("migrate3.in" , "r" , stdin);
//	freopen("qwq.in" , "r" , stdin);
	int c , T; scanf("%d%d" , &c , &T);
	while(T--){
		scanf("%d%lld" , &n , &d);
		for(int i = 1;i <= n;i++) scanf("%lld" , &a[i]);
		if(c <= 10) baoli::solve();
		else wssb::solve();
//		baobao::solve();
	}
	return 0;
}
