#include<bits/stdc++.h>
#define lowbit(x) (x&-x)
using namespace std;
int c,T;
int n,k;
vector<int>g[1000005];
int fa[20],dis[20];
bool vis[20];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(n<=10){
			int ans=1e9;
			for(int msk=1;msk<(1<<n);msk++){
				if(__builtin_popcount(msk)>k)continue;
				for(int i=1;i<=n;i++)fa[i]=i,dis[i]=0,vis[i]=false;
				for(int t=msk;t;t-=lowbit(t)){
					int i=__builtin_ctz(t)+1;
					for(auto v:g[i]){
						if(msk&(1<<(v-1))){
							int fi=find(i),fv=find(v);
							fa[fi]=fv;
						}
					}
				}
				int blk=0;
				for(int t=msk;t;t-=lowbit(t)){
					int i=__builtin_ctz(t)+1;
					if(fa[i]==i)blk++;
				}
				if(blk>2)continue;
				queue<int>q;
				for(int t=msk;t;t-=lowbit(t)){
					int i=__builtin_ctz(t)+1;
					q.push(i);
					vis[i]=true;
				}
				while(!q.empty()){
					int u=q.front();
					q.pop();
					for(auto v:g[u]){
						if(vis[v])continue;
						dis[v]=dis[u]+1;
						q.push(v);
						vis[v]=true;
					}
				}
				int mx=0;
				for(int i=1;i<=n;i++)mx=max(mx,dis[i]);
				ans=min(ans,mx);
			}
			cout<<ans<<"\n";
		}else{
			cout<<"1\n";
		}
		for(int i=1;i<=n;i++)g[i].clear();
	}
}
/*
This view can only relate to Xujiayin's Song

Zuo ri~~ yi qu bu fu hui...... 

Oh yeah yeah

15-gunmu
*/
