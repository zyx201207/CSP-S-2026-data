#include<cstdio>
#include<vector>
#include<map>
#include<fstream>
#include<cmath>
#include<climits>
#define ll long long
ll min(ll a,ll b){
	return a<b?a:b;
}
struct point{
	ll self;
	std::map<ll,ll> go;
}road[500005];
ll dfs(ll x,ll y,std::vector<std::vector<ll>> &dp){
//	printf("a %lld %lld\n",x,y);
	if(x==y){
		return 0;
	}
	ll men=-1;
	for(auto &it:road[x].go){
		if(it.first==0){
			it.second=it.second-it.second*2;
			road[it.first].go[x]=road[it.first].go[x]-road[it.first].go[x]*2;
			continue;
		}
		if(it.second==0){
			continue;
		}
//		printf("b %lld %lld %lld\n",x,it.first,it.second);
		if(it.second>0){
			it.second=it.second-it.second*2;
			road[it.first].go[x]=road[it.first].go[x]-road[it.first].go[x]*2;
			dp[it.first][y]=dfs(it.first,y,dp)-it.second;
//			printf("dp[%lld][%lld]=%lld\n",it.first,y,dp[it.first][y]);
			it.second=it.second-it.second*2;
			road[it.first].go[x]=road[it.first].go[x]-road[it.first].go[x]*2;
		}
		else{
			continue;
		}
		if(men!=-1) men=min(dp[it.first][y],men);
		else men=dp[it.first][y];
//		printf("men=%lld\n",men);
	}
	dp[x][y]=men;
//	printf("dp[%lld][%lld]=%lld\n",x,y,dp[x][y]);
	return dp[x][y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll x,y,z,w,t;
	scanf("%lld%lld%lld%lld%lld",&x,&y,&z,&w,&t);
	std::vector<std::vector<ll>> dp(z+1,std::vector<ll>(z+1,-1));
	for(ll a=1;a<=z;a++){
		scanf("%lld",&road[a].self);
	}
	for(ll a=1;a<=z;a++){
		for(ll r=1;r<=z;r++){
			road[a].go[r]=0;
			road[r].go[a]=0;
		}
	}
	for(ll a=1;a<=y;a++){
		ll h;
		scanf("%lld",&h);
		std::vector<ll> can(z+1,0),v(z+1,0);
		for(ll r=1;r<=h;r++){
			scanf("%lld%lld",&can[r],&v[r]);
		}
		for(ll r=1;r<=h;r++){
			for(ll e=1;e<=h;e++){
				if(can[r]==can[e]) continue;
				road[can[e]].go[can[r]]+=v[r];
				road[can[r]].go[can[e]]+=v[r];
			}
		}
	}
	for(ll a=1;a<=t;a++){
		ll c,h;
		scanf("%lld%lld",&c,&h);
		if(dp[c][h]==-1) printf("%lld\n",dfs(c,h,dp)+std::abs(road[c].self)+std::abs(road[h].self));
		else printf("%lld\n",dp[c][h]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
