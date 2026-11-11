#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int c,T,n,k,tag[N],ans=0;
vector<int>e[N];
void init(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	memset(tag,0,sizeof(tag));
}
namespace sol1{
	int f[N],g[N],rt[N];
	bool vis[N];
	void dfs1(int x,int _fa){
		f[x]=0;
		for(int y:e[x])if(y^_fa){
			dfs1(y,x);
			f[x]=max(f[x],f[y]+1);
		}
		if(tag[x])f[x]=0;
	}
	void dfs2(int x,int _fa){
		g[x]=max(g[x],g[_fa]+1);
		int fir=-1,sec=-1;
		for(int y:e[x])if(y^_fa){
			if(f[y]>fir)sec=fir,fir=f[y];
			else if(f[y]>sec)sec=f[y];
		}
		if(~sec)for(int y:e[x])if(y^_fa)g[y]=(f[y]==fir?sec:fir)+2;
		if(tag[x])g[x]=0;
		for(int y:e[x])if(y^_fa)dfs2(y,x);
	}
	int find(int x){return rt[x]==x?x:rt[x]=find(rt[x]);}
	bool check(){
		for(int i=1;i<=n;i++)rt[i]=(tag[i]?i:n+1),vis[i]=0;
		for(int i=1;i<=n;i++)if(tag[i])for(int j:e[i])if(tag[j])rt[find(j)]=find(i);
		int ret=0;
		for(int i=1;i<=n;i++){
			if(vis[find(i)])continue;
			vis[find(i)]=1;
			ret++;
		}
		return ret<=2;
	}
	int count(int x){
		int res=0;
		for(;x;x>>=1)res+=x&1;
		return res;
	}
	void work(){
		init();
		int ans=0x3f3f3f3f3f3f3f3f;
		for(int s=0;s<(1<<n);s++){
			if(count(s)!=k)continue;
			for(int i=1;i<=n;i++){
				if(s&(1<<(i-1)))tag[i]=1;
				else tag[i]=0;
			}
			if(!check())continue;
			for(int i=1;i<=n;i++)g[i]=0;
			dfs1(1,0);dfs2(1,0);
			int res=0;
			for(int i=1;i<=n;i++)res=max(res,max(f[i],g[i]));
			ans=min(ans,res);
		}
		cout<<ans<<endl;
	}
};
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>c>>T;
	while(T--)sol1::work();
	return 0;
}
