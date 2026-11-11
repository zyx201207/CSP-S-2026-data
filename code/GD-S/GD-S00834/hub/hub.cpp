#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6+5,N = 4e2+5,INF = 1e10+7;
int c,t,n,k,x,y,s[maxn],ans;
bool use[N];
vector<int> g[N];
bool vis[N];
void flo(int x){
	vis[x] = 1;
	for(int i = 0;i < g[x].size();i++){
		if(vis[g[x][i]]) continue;
		if(use[g[x][i]]) flo(g[x][i]);
	}
}
bool check(){
	memset(vis,0,sizeof(vis));
	int cnt = 0;
	for(int i = 1;i <= k;i++){
		if(!vis[s[i]]){
			cnt++;
			if(cnt > 2) return false;
			flo(s[i]);
		}
	}
	return (cnt <= 2);
}
int dis(int x,int y,int len){
	if(len >= n) return INF;
	int ans = INF;
	for(int i = 0;i < g[x].size();i++){
		if(g[x][i] == y) return (len + 1);
		ans = min(ans,dis(g[x][i],y,len+1));
	}
	return ans;
}
int calc(){
	int ret = 0;
	for(int i = 1;i <= n;i++){
		int tmp = INF;
		if(use[i]) continue;
		for(int j = 1;j <= k;j++){
			tmp = min(tmp,dis(i,s[j],0));
		}
		ret = max(ret,tmp);
	}
	return ret;
}
void dfs(int step,int cnt){
	if(cnt == k){
		if(check()){
			int tmp = calc();
			if(tmp < ans){
//				cout << "tmp: " << tmp << "\n";
//				for(int i = 1;i <= k;i++) cout << s[i] << " ";
//				cout << "\n";
			}
			ans = min(ans,tmp);
		}
		return ;
	}
	if(step > n) return ;
	s[cnt+1] = step;
	use[step] = 1;
	dfs(step+1,cnt+1);
	s[cnt+1] = 0;
	use[step] = 0;
	dfs(step+1,cnt);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(t--){
		scanf("%lld %lld",&n,&k);
		for(int i = 1;i <= n;i++) g[i].clear();
		for(int i = 1;i < n;i++) cin >> x >> y,g[x].push_back(y),g[y].push_back(x);
		memset(s,0,sizeof(s));
		memset(use,0,sizeof(use));
		ans = INF;
		dfs(1,0);
		printf("%lld\n",ans);
	}
	return 0;
} 
