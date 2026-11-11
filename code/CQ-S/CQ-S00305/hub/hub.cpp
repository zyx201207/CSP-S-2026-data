#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll __int128
#define mkp make_pair
const int N=1e5+5;
int t,cid,us[N],n,K,D,dp[N],dis[N],vis[N];
vector <int> e[N];
queue <int> q;
int solve(){
	for(int i = 1;i <= n;i++){
		us[i]=vis[i];
		if(vis[i])q.push(i),dis[i]=0;
	}
	while(!q.empty()){
		int now = q.front();q.pop();
		for(auto v:e[now]){
			if(!us[v]){
				us[v]=1;
				dis[v]=dis[now]+1;
				q.push(v);
			}
		}
	}int maxn=0;
	for(int i = 1;i <= n;i++)maxn=max(maxn,dis[i]);
	return maxn;
}int nowrt,cnt,pos[N],de[N],f[N];
void dfs(int u,int fa){
	pos[u]=++cnt;
	for(auto v:e[u]){
		if(v==fa)continue;f[v]=u;
		dfs(v,u);	
		dp[u]=max(dp[u],dp[v]+1);
	}
	if(dp[u]>=D){
		vis[u]=1;
		dp[u]=-D;
	}
}int p[N],len,siz[N];
bool chk(int rt){us[0]=1;
	for(int i = 1;i <= n;i++)dp[i]=vis[i]=us[i]=f[i]=0;
	vis[rt]=1;cnt=0;dfs(rt,0);len=0;
	for(int i = 1;i <= n;i++)if(vis[i])p[++len]=i,us[i]=1;
	sort(p+1,p+len+1); 
	for(int i = 1;i <= len;i++){
		int now = p[i];
		while(!vis[now]&&now!=rt){
			vis[now]=1;
			now=f[now];
		}us[now]=1;
	}int nd=0,tmp=0;
	for(int i = 1;i <= n;i++)if(vis[i])nd++;tmp=nd;
	for(int i = 1;i <= n;i++){
		if(us[i]){
			int now = f[i],cnt1=0;
			while(!us[now]&&now!=rt){
				cnt1++;
				now=f[now];
			}
			tmp=min(tmp,nd-cnt1);
		}
	}return (tmp<=K);
}
bool check(int lim){D=lim;
	for(int i = 1;i <= n;i++)
		if(chk(i))
			return 1;
	return 0;
}int dsu[N];
int getf(int u){
	if(u==dsu[u])return u;
	return dsu[u]=getf(dsu[u]);
}
void work(){
	cin >> n >> K;
	for(int i = 1;i <= n;i++)e[i].clear();
	for(int i = 1,u,v;i < n;i++){
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(cid<=3){
		int ans = n;
		for(int i = 0;i < (1<<n);i++){
			int cnt1=0;
			for(int j = 1;j <= n;j++)vis[j]=0,dsu[j]=j;
			for(int j = 0;j < n;j++)
				if(i&(1<<j))
					cnt1++,vis[j+1]=1;
			for(int j = 1;j <= n;j++){
				for(auto it:e[j]){
					if(vis[j]&&vis[it]){
						dsu[getf(j)]=getf(it);
					}
				}
			}int num=0;
			for(int j = 1;j <= n;j++)if(getf(j)==j&&vis[j])num++;
			if(cnt1==K&&num<=2)ans=min(ans,solve());
		}cout << ans << "\n";
	}else{
		int l = 0,r = n,ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid)){
				ans=mid;
				r=mid-1;
			}else l=mid+1;
		}cout << ans << "\n";
	}
} 
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> cid >> t;
	while(t--)work(); 
	return 0;
}
/*
感觉好困难啊。
我想一下。
二分答案之后怎么判定呢
想了20分钟假题气笑了
那这个应该是这样的。
就是二分答案之后暴力放吗
然后计算最少就是你把所有点拉出来然后建造虚树看最长链长度 
*/
