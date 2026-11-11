#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T> inline void read(T &x){
	T w=1;
	x=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') w=-1;
		c=getchar();
	}
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	x*=w;
}
template<typename T> inline void write(T x){
	if(x<0) putchar('-'),x=(~x)+1;
	if(x>9) write(x/10);
	putchar(x%10^48);
}
const int N=1e6+10;
int n,k;
vector<int>v[N];
int p[N],tot,x[N],y[N];
bool vis[N];
int dis[N],ans;
void dfs(int pos){
	if(tot>=k){
		for(int i=1;i<=n;++i) dis[i]=n+1;
		queue<int>q;
		for(int i=1;i<=k;++i) vis[p[i]]=1,dis[p[i]]=0,q.push(p[i]);
		int cnt=k;
		for(int i=1;i<n;++i){
			if(vis[x[i]]&&vis[y[i]]) --cnt;
		}
		for(int i=1;i<=k;++i) vis[p[i]]=0;
		if(cnt>2) return ;
		while(q.size()){
			int u=q.front();
			q.pop();
			for(int t : v[u]){
				if(dis[t]<=n) continue;
				dis[t]=dis[u]+1;
				q.push(t);
			}
		}
		int ma=0;
		for(int i=1;i<=n;++i) ma=max(ma,dis[i]);
		ans=min(ans,ma);
		return ;
	}
	if(pos>n) return ;
	p[++tot]=pos;
	dfs(pos+1);
	tot--;
	dfs(pos+1);
	return ;
}
void sub1(){
	read(n),read(k);
	for(int i=1;i<=n;++i) v[i].clear();
	for(int i=1;i<n;++i){
		read(x[i]),read(y[i]);
		v[x[i]].emplace_back(y[i]);
		v[y[i]].emplace_back(x[i]);
	}
	ans=n+1;
	dfs(1);
	write(ans),putchar('\n');
}
int mx[N];
int sum[N];
void dfs1(int u,int ff,int lim){
	for(int p : v[u]){
		if(p==ff) continue;
		dfs1(p,u,lim);
		mx[u]=max(mx[u],mx[p]+1);
		sum[u]+=sum[p];
	}
	if(mx[u]>lim||sum[u]) sum[u]++;
}
int id,dfn[N],top[N];
void dfs2(int u,int ff){
	dfn[u]=++id;
	for(int p : v[u]){
		if(p==ff) continue;
		dfs2(p,u);
	}
	top[u]=id;
}
int dep[N];
int dep2[N];
void dfs3(int u,int ff){
	for(int p : v[u]){
		if(p==ff) continue;
		dep[p]=dep[u]+1;
		dfs3(p,u);
	}
}
bool dfs5(int u,int ff,int rt,int lim){
	bool fl=1;
	fl&=(min(dep[u],dep2[u])<=lim);
	for(int p : v[u]){
		if(p==ff||dfn[rt]<=dfn[p]&&top[p]<=top[rt]) continue;
		dep2[p]=dep2[u]+1;
		fl&=dfs5(p,u,rt,lim);
	}
	return fl;
}
int dfs4(int u,int ff,int lim){
	for(int i=1;i<=n;++i){
		dep2[i]=0;
	}
	bool fl=dfs5(u,u,u,lim);
	int tmps=n+1;
	if(fl){
		tmps=1;
		for(int i=1;i<=n;++i) mx[i]=sum[i]=0;
		for(int p : v[u]){
			if(p==ff) continue;
			dfs1(p,ff,lim);
			tmps+=sum[p];
		}
	}
	for(int p : v[u]){
		if(p==ff) continue;
		tmps=min(tmps,dfs4(p,u,lim));
	}
	return tmps;
}
bool chk(int mid){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) mx[j]=sum[j]=0;
		int tmp=1;
		for(int p : v[i]){
			dfs1(p,i,mid);
			tmp+=sum[p];
		}
		if(tmp<=k) return 1;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) dep[j]=0;
		dfs3(i,0);
		for(int j=1;j<=n;++j) mx[j]=sum[j]=0;
		int tmp=1;
		for(int p : v[i]){
			dfs1(p,i,mid);
			tmp+=sum[p];
		}
		for(int p : v[i]){
			tmp-=sum[p];
			int tmps=dfs4(p,i,mid);
			if(tmp+tmps<=k) return 1;
		}
	}
	return 0;
}
void sub2(){
	read(n),read(k);
	for(int i=1;i<=n;++i) v[i].clear();
	for(int i=1;i<n;++i){
		int x,y;
		read(x),read(y);
		v[x].emplace_back(y),v[y].emplace_back(x);
	}
	int l=0,r=n,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(chk(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	write(ans),putchar('\n');
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int cid,T;
	read(cid),read(T);
	while(T--){
		if(cid<=1) sub1();
//		if(cid<=6) sub2();
	}
	return 0;
}


