#include<bits/stdc++.h>

using namespace std;
/*
scanf("%d", &x);
printf("%d", x);
*/
#define ll long long
const int M = 5e5 + 10, N = 500 + 10;
const ll kInf = LLONG_MAX;
int n, m, c, d, q;
int w[M];
struct node{
	int to;
	ll q;
};
vector<node>v[M + N];

ll dis[N + M];
struct type{
	int t;
	ll d;
	
	bool operator <(const type& other)const{
		return d > other.d;
	}
};

void init(){
	fill(dis + 1, dis + 1 + m + n, kInf);
}

priority_queue<type>Q;
ll dij(int stt, int nd){
	dis[stt] = 0ll;
	Q.push((type){stt, 0ll}); 
	
	type w;
	while(!Q.empty()){
		w = Q.top();
		Q.pop();
		if(dis[w.t] != w.d) continue;
		
		for(int i = 0, tt; i < v[w.t].size(); i++){
			tt = v[w.t][i].to;
			ll z = v[w.t][i].q;
			if(dis[tt] > dis[w.t] + z){
				dis[tt] = dis[w.t] + z;
				Q.push((type){tt, dis[tt]});
			}
		} 
	}
	
	return dis[nd];
} 

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++){
		scanf("%d", &w[i]);
	}
	
	if(c <= 6){
		for(int i = 1, k; i <= n; i++){
			scanf("%d", &k);
			ll z;
			for(int j = 1, to; j <= k; j++){
				scanf("%d", &to);
				scanf("%lld", &z);
				v[m + i].push_back((node){to, z});
				v[to].push_back((node){m + i, z});
			}
		}
		
		int now, too;
		while(q--){
			init();
			scanf("%d%d", &now, &too);
			printf("%lld\n", (ll)1ll * w[now] + (ll)1ll * w[too] + dij(now, too));
		}
	}else if(c >= 7 && c <= 11){
		for(int i = 1, k; i <= n; i++){
			scanf("%d", &k);
			ll z; int to;
			if(k == 1){
				scanf("%d%lld", &to, &z);
				continue;
			}
			
			int too; ll zzz;
			scanf("%d%lld", &to, &z);
			scanf("%d%lld", &too, &zzz);
			v[to].push_back((node){too, zzz + z});
			v[too].push_back((node){to, zzz + z}); 
		}
		int now, too;
		while(q--){
			fill(dis + 1, dis + 1 + m, kInf);
			scanf("%d%d", &now, &too);
			printf("%lld\n", (ll)1ll * w[now] + (ll)1ll * w[too] + dij(now, too));
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
