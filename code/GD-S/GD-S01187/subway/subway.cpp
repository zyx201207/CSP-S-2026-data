#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
class cnm{
public:
	ll first,second,third;
};
ll c,n,m,d,q,k;
ll w[502],a[502][50005],t[502][50005];
ll x,y,ans=LLONG_MAX;
vector<cnm>graph[502];//Â·Ïß 
//ll BFS(ll x,ll y){
//	queue<ll>q;
//	q.push(x);
//	ll time=0,now=x;
//	while(!q.empty()){
//		for(pair<ll,ll> &it:graph[now]){
//			q.push(it);
//		}
//		now=q.front();
//		q.pop();
//		if(now==y){
//			return time;
//		}
//	}
//	return time;
//}
void DFS(ll now,ll end,ll time=0){
	if(now==end){
		ans=min(ans,time);
		return;
	}
	if(!graph[now].empty()) DFS(graph[now][0].first,end,time+w[graph[now][0].first]+t[graph[now][0].second][graph[now][0].third]);
	return;//ERROR
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(ll i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
//	memset(t,127,sizeof t);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&k);
		for(ll j=1;j<=k;j++){
			scanf("%lld%lld",&a[i][j],&t[i][j]);
		}
		for(ll j=1;j<k;j++){
			for(ll l=j+1;l<=k;l++){
				graph[a[i][j]].push_back(cnm{a[i][l],i,j});
			}
		}
	}
	while(q--){
		ans=LLONG_MAX; 
		scanf("%lld%lld",&x,&y);
//		if(7<=c && c<=11){//Only 20pts...
//			printf("%lld",DFS(x,y));
//			continue;
//		}
		DFS(x,y);
		printf("%lld\n",(ans==LLONG_MAX? 88:ans));
	}
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
