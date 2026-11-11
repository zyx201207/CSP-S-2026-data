#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N=1e6+10,mod=998244353;
typedef pair<int,int> pii;
typedef long long ll;
/*

*/
int C,T=1;
int head[N<<1],edge[N<<1],last[N<<1],idx;
void add(int u,int v){
	edge[++idx]=v;
	last[idx]=head[u],head[u]=idx;
}
int n,k,dis[N],cnt[N],deg[N],del[N<<1],res;
int cp[N],cq[N],vis[N];
void Solve(int cnt[],int col){
	queue<int> q;
	for(int i=0;i<=n;i++) dis[i]=cnt[i]=deg[i]=0;
	for(int i=1;i<n;i++) if(!del[i*2]) deg[edge[i*2]]++,deg[edge[i*2-1]]++;
	for(int i=1;i<=n;i++) if(vis[i]==col&&deg[i]==1) q.push(i);
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int i=head[u];i;i=last[i]){
			if(del[i]) continue;
			int v=edge[i]; --deg[v];
			if(deg[v]) dis[v]=max(dis[v],dis[u]+1);
			if(deg[v]==1) q.push(v);
		}
	}
	for(int i=n;i;i--) cnt[dis[i]]++;
	for(int i=n;~i;i--) cnt[i]+=cnt[i+1];
}
void dfs(int u,int fa,int col){ vis[u]=col;
	for(int i=head[u];i;i=last[i])
		if(edge[i]!=fa) dfs(edge[i],u,col);
}
void Case1(){
	for(int i=1;i<n;i++){
		del[i*2]=del[i*2-1]=1;
		int u=edge[i*2],v=edge[i*2-1];
		dfs(u,v,1),dfs(v,u,2);
		Solve(cp,1),Solve(cq,2);
		
		int p=n-1,q=0;
		for(int i=0;i<n;i++) if(cq[i]<k) {q=i;break;};
		for(int kp=1;kp<k;kp++){
			int kq=k-kp;
			while(p&&cp[p-1]<=kp) --p;
			while(cq[q]>kq) ++q;
			res=min(res,max(p,q));
		}
		del[i*2]=del[i*2-1]=0;
	}
	cout<<res<<"\n";
}
void Case2(){
	
}
void mian(){
	cin>>n>>k; res=0; idx=0;
	for(int i=1;i<=n;i++) head[i]=vis[i]=0;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		add(u,v),add(v,u);
	}
	Solve(cnt,0);
	for(int i=0;i<n;i++) if(cnt[i]<=k) {res=i;break;}
	if(C==13||C==14) return Case2();
	return Case1();
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>C>>T; while(T--) mian();
	return 0;
}

