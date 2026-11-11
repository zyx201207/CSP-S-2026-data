#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fll
#define uint unsigned int
#define ulong unsigned long
using namespace std;

namespace AeeE5x{
	int n,k;
	vector<int> g[1000010];
	
	int fa[1000010];
	static inline int find(int x){while(x!=fa[x]) x=fa[x]=fa[fa[x]];return x;}
	static inline void merge(int x,int y){
		x=find(x),y=find(y);
		if(x==y) return;
		fa[x]=y;
	}
	
	bool chosen[1000010];
	int chs[1000010],dis[1000010];
	int check(){
		for(int i=1;i<=k;i++) fa[chs[i]]=chs[i];
		for(int x=1;x<=n;x++) for(int y:g[x]) if(chosen[x]&&chosen[y]) merge(x,y);
		
		int cnt=0;
		for(int i=1;i<=k;i++) cnt+=(chs[i]==fa[chs[i]]);
		if(cnt>2) return inf;
		
		for(int i=1;i<=n;i++) dis[i]=(chosen[i]?0:inf);
		queue<int> q;
		for(int i=1;i<=k;i++) q.push(chs[i]);
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int y:g[x]) if(dis[y]>dis[x]+1) dis[y]=dis[x]+1,q.push(y);
		}
		
		int ans=0;
		for(int i=1;i<=n;i++) ans=max(ans,dis[i]);
		
		return ans;
	}
	
	const int Tc=100;
	void main(){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			g[x].push_back(y),g[y].push_back(x);
		}
		
		int ans=inf;
		for(int b=0;b<(1<<n);b++){
			if(__builtin_popcount(b)!=k) continue;
			int w=0;
			for(int i=1;i<=n;i++){
				chosen[i]=(b>>(i-1)&1);
				if(chosen[i]) chs[++w]=i;
			}
			ans=min(ans,check());
		}
		
		cout<<ans<<"\n";
	}
	
	void clear(){
		for(int i=1;i<=n;i++) g[i].clear();
	}
}

int main(){
//	freopen("samples\\hub\\hub2.in","r",stdin);
//	freopen("samples\\hub\\hub.out","w",stdout);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	
	int testid,T;cin>>testid>>T;
	while(T--) AeeE5x::main(),AeeE5x::clear();
	
	#ifdef TakanashiHoshino
	cerr<<"\nUsed time: "<<clock()*1.0/CLOCKS_PER_SEC<<"s.\n";
	#endif
	return 0;	
}

/*

Oct31==Dec25?

hub

*/
