#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cerr<<#x<<':'<<x<<endl
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const int N=1e3+5,inf=1e18;
int c,T;
int n,k;
int f[N],vis[N];
int find(int x){
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}
int d[N];
vector<int> G[N];
void dfs(int x,int fa,int st,int dep){
	if(vis[x]){
		d[st]=min(d[st],dep);
		return;
	}
	for(int y:G[x]){
		if(y==fa) continue;
		dfs(y,x,st,dep+1);
	}
}
void dfs1(int x,int fa,int dep){
	d[x]=min(d[x],dep);
	for(int y:G[x]){
		if(y==fa) continue;
		dfs1(y,x,dep+1);
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(c<=3){
		int ans=inf;
		for(int bit=0;bit<(1<<n);bit++){
			if(__builtin_popcount(bit)!=k) continue;
			for(int i=1;i<=n;i++){
				f[i]=i;
				if(bit&(1<<(i-1))){
					vis[i]=1;
				}else vis[i]=0;
			}
			for(int i=1;i<=n;i++){
				if(vis[i]){
					for(int j:G[i]){
						int fi=find(i),fj=find(j);
						if(vis[j]&&fi!=fj) f[fi]=fj;
					}
				}
			}
			int a=0,b=0,flag=1;
			for(int i=1;i<=n;i++){
				if(vis[i]){
					int fi=find(i);
					if(b&&fi!=b&&fi!=a){
						flag=0;
						break;
					}
					if(a&&fi!=a) b=fi;
					if(!a) a=fi;
				}
			}
			if(!flag) continue;
			for(int i=1;i<=n;i++) d[i]=inf;
			for(int i=1;i<=n;i++) dfs(i,0,i,0);
			int sum=0;
			for(int i=1;i<=n;i++) sum=max(sum,d[i]);
			ans=min(ans,sum);
		}
		cout<<ans<<endl;
		return;
	}
	if(c<=7){
		int ans=inf;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int i=1;i<=n;i++) d[i]=inf;
				dfs1(i,0,0),dfs1(j,0,0);
				int sum=0;
				for(int i=1;i<=n;i++) sum=max(sum,d[i]);
				ans=min(ans,sum);
			}
		}
		cout<<ans<<endl;
		return;
	}
	if(c<=14){
		
	} 
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	IOS;
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
/*
自从省选结束就退役了 
一直没有写过代码
回来娱乐一下
结果丢脸丢大了

几年OI没有什么成就
文化课也学得不好
 
Only blue
Only blue
爱让人好忧郁
我的心 我的心 蓝蓝的

我只想哭 只想哭 只想哭

还没上过迷惑行为大赏，拜托了
luogu uid:(被封号了) 
*/
