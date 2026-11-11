#include <bits/stdc++.h>
using namespace std;
int c , n , m , d , q , a[550000] , zhan[550000][22] , now[550000] ;
long long dis[550][550] ;
int xian[550][550000] , fxian[550] , fzhan[550000];
vector<int> xian1[550] ; 
void dist(int x){
	queue<int> q ;
	int tt ;
	long long minn ;
	for(int i = 1 ; i <= m ; i++)fzhan[i] = 0 ;
	long long maxn = LONG_LONG_MAX ;
	maxn/=10 ;
	for(int i = 1 ; i <= n ; i++){
		dis[x][i] = maxn ;
		fxian[i] = 0 ;
	}
	dis[x][x] = 0 ;
	int tt1	;
	q.push(x) ;
	while(q.size()){
		minn = maxn ;
		while(fxian[q.front()])q.pop() ;
		if(q.empty())break ;
		tt = q.front() ;
		q.pop() ;
		fxian[tt] = 1 ;
		int l = xian1[tt].size() ;
		for(int k = 0 ; k < l ; k++){
			int i = xian1[tt][k] ;
			if(fzhan[i])continue;
			if(xian[tt][i]){
				fzhan[i] = 1 ;
				for(int j = 1 ; j <= now[i] ; j++){
					if(fxian[zhan[i][j]]==0){
						dis[x][zhan[i][j]] = min(dis[x][zhan[i][j]],xian[tt][i]+xian[zhan[i][j]][i]+dis[x][tt]) ;
						if(minn > dis[x][zhan[i][j]]){
							minn = dis[x][zhan[i][j]] ;
							q.push(zhan[i][j]) ;
						}
					}
				}
			}
		}
	}
	return ;
}
long long find(int u , int v){
	long long ans = LONG_LONG_MAX , maxn = LONG_LONG_MAX ;
	maxn/=10 ;
	for(int i = 1 ; i <= now[u] ; i++){
		for(int j = 1 ; j <= now[v] ; j++){
			if(dis[zhan[u][i]][zhan[v][j]]!=maxn){
				ans = min(ans,dis[zhan[u][i]][zhan[v][j]]+xian[zhan[u][i]][u]+xian[zhan[v][j]][v]) ;
			}else if(dis[zhan[v][j]][zhan[u][i]]!=maxn){
				ans = min(ans,dis[zhan[v][j]][zhan[u][i]]+xian[zhan[u][i]][u]+xian[zhan[v][j]][v]) ;
			}
		}
	}
	return ans+a[u]+a[v] ;
}
int main(){
	freopen("subway.in","r",stdin) ;
	freopen("subway.out","w",stdout) ;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q) ;
	for(int i = 1 ; i <= m ; i++){
		scanf("%d",&a[i]) ;
	}
	for(int i = 1 ; i <= n ; i++){
		int k ;cin >> k ;
		for(int j = 1 ; j <= k ; j++){
			int v , w ;
			scanf("%d%d",&v,&w) ;
			zhan[v][(++now[v])] = i ;
			xian[i][v] = w ;
			xian1[i].push_back(v) ;
		}
	}
	for(int i = 1 ; i <= n ; i++){
		dist(i) ;
	}
	for(int i = 1 ; i <= q ; i++){
		int u , v ;
		scanf("%d%d",&u,&v) ;
		long long ans = find(u,v) ;
		printf("%lld\n",ans) ;
	}
	return 0 ;
}
