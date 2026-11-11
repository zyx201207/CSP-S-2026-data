/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+7,inf=1e9+7;
int n,m,c,T,pre[N],nxt[N],sz[N],sz_[N],idx,u,v,head[N],to[N],last[N],dp[N];
ll d,x[N],ans,sum[N];
/*void dfs(int u,bool op){
	if(op) sz[u]=0;
	else sz_[u]=0;
	for(int i=head[u];i;i=last[i]){
		dfs(to[i],op);
		if(op) sz[u]+=sz[to[i]];
		else sz_[u]+=sz_[to[i]];
	}
	if(op){
		if(!(pre[u]==u-1||pre[pre[u]+1]!=pre[pre[u]])) sz[u]=1;
		else sz[u]++;
	}
	else{
		if(nxt[u]!=u+1&&nxt[u]){
			sz_[u]++;
			//cout<<u<<" "<<ans<<'\n';
			ans+=1ll*sz_[u]*
			(sum[nxt[nxt[u]-1]]-sum[nxt[nxt[u]-2]]);
		}
		if(!nxt[u]) sz_[u]=0;
		else if(!(nxt[u]==u+1||nxt[nxt[u]-1]!=nxt[nxt[u]])){
			sz_[u]=1;
		}
		else sz_[u]++;
	}
}
void add(int u,int v){
	++idx;
	to[idx]=v,last[idx]=head[u],head[u]=idx;
}
void func(int l,int r){
	//cout<<l<<" "<<r<<'\n';
	idx=r,nxt[r]=0;
	for(int i=r-1;i>=l;i--){
		while(x[idx]-x[i]>d) --idx;
		nxt[i]=idx,add(i,nxt[i]);
	}
	dfs(l,1),sum[l-1]=0;
	for(int i=l;i<=r;i++) sum[i]=sum[i-1]+sz[i];
	//for(int i=l;i<=r;i++) cout<<sz[i]<<" ";
	for(int i=l;i<=r;i++) head[i]=0;
	for(int i=1;i<=idx;i++) to[i]=last[i]=0;
	for(int i=r-1;i>=l;i--) add(nxt[i],i);
	dfs(r,0);
	for(int i=l;i<=r;i++) sum[i]=sz[i]=sz_[i]=head[i]=0;
	for(int i=1;i<=idx;i++) to[i]=last[i]=0;
}*/
int calc(int u,int v){
	int res=0;
	for(int i=u+1;i<=v;i++){
		int mn=inf,cnt=0;
		for(int j=u;j<i;j++){
			if(x[i]-x[j]<=d){
				if(dp[j]<mn) mn=dp[j],cnt=1;
				else if(dp[j]==mn) cnt++;
			}
		}
		res=cnt;
	}
	return res;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		/*int cnt=1;
		for(int i=2;i<=n;i++){
			if(x[i]-x[i-1]>d) func(cnt,i-1),cnt=i;
		}
		func(cnt,n);*/
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++) ans+=calc(i,j)==2;
		}
		cout<<ans<<'\n',ans=0;
	}
	return 0;
}
