/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
#include<bits/stdc++.h>
using namespace std;
const int N=4007,inf=1e9+7;
int n,m,u,v,k,head[N],to[N*2],last[N*2],c,T,idx,res,ans;
bool vis[N],op[N];
void add(int u,int v){
	++idx;
	to[idx]=v,last[idx]=head[u],head[u]=idx;
}
void dfs(int u,int fa){
	if(op[u]) return;
	vis[u]=1;
	for(int i=head[u];i;i=last[i]) if(to[i]!=fa) dfs(to[i],u);
}
bool check(){
	int cnt=0,cnt_=0;
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=1;i<=n;i++){
		if(op[i]) cnt_++;
		if(op[i]&&!vis[i]) dfs(i,0),cnt++;
	}
	return cnt<=2&&cnt_<=k;
}
void find(int u,int fa,int k){
	if(op[u]){
		res=min(res,k);
		return;
	}
	for(int i=head[u];i;i=last[i]){
		if(to[i]!=fa) find(to[i],u,k+1); 
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++) cin>>u>>v,add(u,v),add(v,u);
		ans=inf;
		for(int i=1;i<(1<<n);i++){
			for(int j=1;j<=n;j++) op[j]=(i>>(j-1)&1);
			if(!check()) continue;
			int cnt=0;
			for(int i=1;i<=n;i++){
				res=inf,find(i,0,0),cnt=max(cnt,res);
			}
			ans=min(ans,cnt);
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++) head[i]=0;
		for(int i=1;i<=idx;i++) to[i]=last[i]=0;
	}
	return 0;
}
