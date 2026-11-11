#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=1e6+5,M=4005;
vector<int>e[N];
int sz[N],n,type,_,m,f[M][M],k,md[N],mxd[N];
bool flag,vis[N];
int read(){
	int x(0);char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	do x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	while(isdigit(ch));
	return x;
}
void Clear(){
	for(int i=1;i<=n;++i)
		e[i].clear();
}
int find(int u,int fa){
	md[u]=0;
	int res(0);
	for(auto v : e[u]){
		if(v==fa)continue;
		res+=find(v,u);
		md[u]=max(md[u],md[v]+1);
	}
	if(md[u]>=k||res)return res+1;
	return 0;
}
void Fd(int u,int fa,int deep){
	md[u]=deep;
	for(auto v : e[u]){
		if(v==fa)continue;
		Fd(v,u,deep+1);
	}
}
void dfs(int u,int fa,int td,int vd,int mxdis){
	if(mxdis>k)return;
	if(f[fa][u]+f[vd][td]<=m){
		flag=1;
		return;
	}
	int mx(-1e9),mx2(-1e9);
	for(auto v : e[u]){
		if(v==fa)continue;
		if(mxd[v]+1>mx)mx2=mx,mx=mxd[v]+1;
		else mx2=max(mx2,mxd[v]+1);
	}
	for(auto v : e[u]){
		if(v==fa)continue;
		int d=mxdis;
		if(!vis[u])d=max(d,0);
		if(mxd[v]+1==mx)d=max(d,mx2);
		else d=max(d,mx);
		dfs(v,u,td,vd,d+1);
		if(flag)return;
	}
}
void push(int u,int fa){
	vis[u]=1;
	for(auto v : e[u]){
		if(v==fa)continue;
		push(v,u);
	}
}
void push(int u,int fa,int deep){
	if(deep>k)return;
	vis[u]=1;
	for(auto v : e[u]){
		if(v==fa)continue;
		push(v,u,deep+1);
	}
}
void init(int u,int fa){
	if(!vis[u])mxd[u]=0;
	else mxd[u]=-1e9;
	for(auto v : e[u]){
		if(v==fa)continue;
		init(v,u);
		mxd[u]=max(mxd[u],mxd[v]+1);
	}
}
bool check(int mid){
	k=mid,flag=0;
	if(type>=13&&type<=14){
		int p=n/2+1-k;
		if(p<=k+m-1)return true;
		if((p-(k+m-2))/2+1<=mid)return true;
		return false;
	}
	for(int i=1;i<=n;++i){
		int num=max(1,find(i,0));
		if(num<=m)return true;
		for(auto v : e[i])
			f[i][v]=max(1,find(v,i));
	}
	for(int i=1;i<=n;++i)
		for(auto v : e[i]){
			fill(vis+1,vis+1+n,0);
			flag=0;
			push(v,i);
			push(i,v,1);
			init(i,v);
			dfs(i,v,v,i,-1e9);
			if(flag)return true;
		}
	return false;
}
void solve(){
	n=read(),m=read();
	Clear();
	for(int i=1,u,v;i<n;++i){
		u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(n==m){
		puts("0");
		return;
	}
	int l(1),r(n);
	while(l<r){
		int mid((l+r)>>1);
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%d\n",r);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	type=read(),_=read();
	while(_--)solve();
	return 0;
} 
