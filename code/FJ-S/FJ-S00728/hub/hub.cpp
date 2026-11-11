#include<bits/stdc++.h>
#define N 1000005
using namespace std;
inline int read(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?-x:x;
}
int c,T,n,k;
vector<int>edge[N];
void add(int u,int v){
	edge[u].push_back(v);
}
int p[N];
bool vis[N];
int val[N];
int ans=1e8;
namespace Sub1{
	void dfs(int p,int u,int fa,int now){
		if(vis[u]){
			val[p]=now;
			return;
		}
		for(int v:edge[u]){
			if(v==fa)continue;
			dfs(p,v,u,now+1);
		}
	}
	bool chk[N];
	void check(int u,int fa){
		chk[u]=1;
		for(int v:edge[u]){
			if(v==fa)continue;
			if(vis[v])check(v,u);
		}
	}
	void dfs_p(int u,int st){
		if(u>k){
			//chk
			int cnt=0;
			for(int i=1;i<=n;i++)chk[i]=0;
			for(int i=1;i<=k;i++)vis[p[i]]=1;
			for(int i=1;i<=k;i++){
				if(!chk[p[i]]){
					++cnt;
					check(p[i],0);
				}
			}
			if(cnt>2)return;
			
			//calc
			int res=0;
			for(int i=1;i<=n;i++)vis[i]=0;
			for(int i=1;i<=k;i++)vis[p[i]]=1;
			for(int i=1;i<=n;i++){
				val[i]=1e8;
				dfs(i,i,0,0);
			}
			for(int i=1;i<=n;i++){
				res=max(res,val[i]);
			}
			ans=min(ans,res);
			return;
		}
		for(int i=st+1;i<=n;i++){
			p[u]=i;
			dfs_p(u+1,i);
		}
	}
}
namespace Sub2{
	int Ans(){
		int p=(n-1)/2;
		if(p&1){
			if(k==1)return (n+1)/2;
		}
		else{
			if(k==1)return n/2+1;
		}
		return (p/2)/2+1-(k-1)/2;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read(),k=read();
		for(int i=1;i<=n;i++){
			edge[i].clear();
		}
		for(int i=1;i<=n-1;i++){
			int u=read(),v=read();
			add(u,v),add(v,u);
		}
		ans=1e8;
		if(c<=3){
			for(int i=1;i<=k;i++)p[i]=0;
			Sub1::dfs_p(1,0);
			cout<<ans<<"\n";
		}
		if(c==13||c==14){
			cout<<Sub2::Ans()<<"\n";
		}
	}
	return 0;
}

