#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N = 1e6+5;
const int INF = 1e18;
int c,t,n,k,f[4005][4005],siz[N],mxdep[N],mxdep2[N],gg[4005],g1[4005],g2[4005],dis[4005],ans,cnt;
pii e[N];
vector<int> g[N];
void prep(int nw,int fa,int rt){
	siz[nw]=1,dis[nw]=(nw==rt?0:dis[fa]+1),mxdep[nw]=mxdep2[nw]=0;
	for(auto ff:g[nw]){
		if(ff==fa)continue;
		prep(ff,nw,rt);
		siz[nw]+=siz[ff];
		if(mxdep[ff]+1>mxdep[nw])mxdep2[nw]=mxdep[nw],mxdep[nw]=mxdep[ff]+1;
		else if(mxdep[ff]+1>mxdep2[nw])mxdep2[nw]=mxdep[ff]+1;
	}
}
void dfs(int nw,int fa){
	for(auto ff:g[nw]){
		if(ff==fa)continue;
		dfs(ff,nw);
	}
	for(int i = 0;i<=min(siz[nw],k);++i)f[nw][i]=INF;
	f[nw][0]=mxdep[nw]+1,f[nw][1]=0;
	int nwsiz=1;
	for(auto ff:g[nw]){
		if(ff==fa)continue;
		for(int j = 0;j<=min(k,nwsiz+siz[ff]);++j)gg[j]=INF;
		for(int j = 1;j<=min(nwsiz,k);++j){
			for(int l = 0;l<=min(siz[ff],k)&&j+l<=k;++l){
				gg[j+l]=min(gg[j+l],max(f[nw][j],f[ff][l]));
			}
		}
		for(int j = 1;j<=min(nwsiz+siz[ff],k);++j)f[nw][j]=gg[j];
		nwsiz+=siz[ff];
	}
}
void dfs2(int nw,int fa,int lst){
	for(int j = 1;j<=min(siz[nw],k);++j){
		g1[j]=min(g1[j],max(f[nw][j],lst));
	}
	for(auto ff:g[nw]){
		if(ff==fa)continue;
		if(mxdep[ff]+1==mxdep[nw])dfs2(ff,nw,max(lst,mxdep2[nw])+1);
		else dfs2(ff,nw,max(lst,mxdep[nw])+1);
	}
}void dfs3(int nw,int fa,int lst){
	for(int j = 1;j<=min(siz[nw],k);++j){
		g2[j]=min(g2[j],max(f[nw][j],lst));
	}
	for(auto ff:g[nw]){
		if(ff==fa)continue;
		if(mxdep[ff]+1==mxdep[nw])dfs3(ff,nw,max(lst,mxdep2[nw])+1);
		else dfs3(ff,nw,max(lst,mxdep[nw])+1);
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
		cin>>n>>k;
		for(int i = 1;i<=n;++i)g[i].clear();
		int u,v;
		for(int i = 1;i<n;++i){
			cin>>u>>v;
			g[u].push_back(v),g[v].push_back(u);
			e[i]={u,v};
		}
		ans=INF;
		for(int i = 1;i<n;++i){
			u=e[i].first,v=e[i].second;
			prep(u,v,u),prep(v,u,v);
			dfs(u,v),dfs(v,u);
			for(int j = 0;j<=k;++j)g1[j]=g2[j]=INF;
			dfs2(u,v,0),dfs3(v,u,0);
			cnt=INF;
			for(int j = 1;j<=k;++j)cnt=min(cnt,max(g1[j],g2[k-j]));
			ans=min(ans,cnt);
		}
		cout<<ans<<'\n';
	}
    return 0;
}
