#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100,inf=1e17;
int n,k,ans;
vector<int>g[N];
bool vis[N];
bool check(){
	int cnt=2*k;
	for(int u=1;u<=n;u++){
		if(!vis[u]) continue;
		for(int v:g[u]) if(vis[v]) cnt--;
	}if(cnt==4) return 1;
	return 0;
}
int bfs(int u){
	queue<int>q;q.push(u);
	queue<int>d;d.push(0);
	while(!q.empty()){
		int u=q.front(),dis=d.front();q.pop(),d.pop();
		for(int v:g[u]){
			if(vis[v]) return dis+1;
			q.push(v);d.push(dis+1);
		}
	}return 0;
}
void ddd(int x){
	if(x>k){
		if(!check()) return;
		int sum=0;
		for(int i=1;i<=n;i++) if(!vis[i]) sum=max(sum,bfs(i));
		ans=min(ans,sum);
		return;
	}for(int i=1;i<=n;i++) if(!vis[i]) vis[i]=1,ddd(x+1),vis[i]=0;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int C,T;cin>>C>>T;
	while(T--){
		cin>>n>>k;ans=inf;
		for(int i=1;i<=n;i++) g[i].clear(),vis[i]=0;
		for(int i=1,x,y;i<n;i++) cin>>x>>y,g[x].push_back(y),g[y].push_back(x);
		ddd(1);cout<<ans<<"\n";
	}
	return 0;
}
/*
17:10:55 还有一个小时，但我不想打了，看完感觉性质能打，但有点小细节，不想动脑了，连暴力都不想打，个人认为224应该够了（千万别挂） 
17:12:50 发呆太无聊了，尝试把O(不知道)打了，获得高额5分 
17:40:23 调出暴力了，喜提5分！！！
预估难度：紫？黑？反正是我不会的 
期望：100+100+24+5=229
实际：？
229应该够吧。。。 感觉一等线220左右，不要太多大佬切T3啊~ 
18:18:14 无疑是饥饿的 
已检查freopen 
*/
