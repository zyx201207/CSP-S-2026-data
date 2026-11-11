#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,m,u,v,cnt,mid,flag,tp,lg[1000005],mx[1000005],st[1000005],ID[1000005],ans[1000005],MX[1000005],son[1000005],son2[1000005],f[1000005],g[1000005],h[1000005],ls[1000005],zf[1000005],f1[1000005],f2[1000005],fa[1000005],dep[1000005],id[1000005],nw[1000005],top[1000005],ed[1000005];
int s1[21][1000005],s2[21][1000005];
vector<int>ve[1000005];
vector<array<int,3>>ve2[1000005];
//fu：子树内最大深度 zfu：子树外最大深度 f1u：子树内fu>=mid的个数 f2u：子树外fu>=mid的个数 
//hu 目前的根r，u的长儿子 lsu 一直跳hu，且hu=fau，最终跳到哪 
void dfs1(int u,int fa){
	dep[u]=dep[fa]+1,mx[u]=dep[u],son[u]=0,::fa[u]=fa;
	for(int v:ve[u])if(v^fa){
		dfs1(v,u),mx[u]=max(mx[u],mx[v]);
		if(mx[v]>mx[son[u]])son[u]=v;
	}
	f[u]=mx[u]-dep[u];
}
void Dfs(int u,int x){
	zf[u]=x;int mx1=f[son[u]],mx2=0;son2[u]=0;
	for(int v:ve[u])if(v!=fa[u]&&v!=son[u])if(mx2<=f[v]+1)mx2=f[v]+1,son2[u]=v;g[u]=mx2;
	for(int v:ve[u])if(v^fa[u])Dfs(v,max(x,v==son[u]?mx2:mx1)+1);
}
void dfs2(int u,int tp){
	id[u]=++cnt,nw[id[u]]=u,top[u]=tp,ed[tp]=u;if(son[u])dfs2(son[u],tp);
	for(int v:ve[u])if(v!=fa[u]&&v!=son[u])dfs2(v,v);
}
void dfs3(int u){f1[u]=f[u]>=mid;for(int v:ve[u])if(v!=fa[u])dfs3(v),f1[u]+=f1[v];}
void dfs4(int u,int x){
	f2[u]=x;for(int v:ve[u])if(v^fa[u])x+=f1[v];
	for(int v:ve[u])if(v^fa[u])dfs4(v,x-f1[v]+(zf[v]-1>=mid));
}
void chk(int u,int v,int p){
	if(v!=p)if(zf[p]+min(dep[u]-dep[p],dep[v]-dep[p])>mid)return;
	m++,ve2[u].push_back({v,p,m});if(v^p)ve2[v].push_back({u,p,m});
	/*
	int x=fa[u],lst=u;
	while(x^p){
		int mx=lst==son[x]?g[x]:f[x];
		if(mx+min(dep[u]-dep[x],dep[x]-dep[p]+dep[v]-dep[p])>mid)return 0;
		lst=x,x=fa[x];
	}
	if(v!=p){
		x=fa[v],lst=v;
		while(x^p){
			int mx=lst==son[x]?g[x]:f[x];
			if(mx+min(dep[v]-dep[x],dep[x]-dep[p]+dep[u]-dep[p])>mid)return 0;
			lst=x,x=fa[x];
		}
	}
	return 1;*/
}
void dfs5(int u){//令u为一个根，找另外一个
	int sum=0;for(int v:ve[u])if(v^fa[u])sum+=f1[v];sum+=f2[u];
	if(sum<=k)flag=1;
	for(int v:ve[u])if(v^fa[u]){
		int ss=sum-f1[v]+1;if(ss>=k)continue;
		int l=id[v],r=id[ed[top[v]]],res=0;
		while(l<=r){int M=l+r>>1,x=nw[M];if(f1[x]+(f[x]<mid)+ss<=k)res=x,r=M-1;else l=M+1;}
		//cout<<"?????? "<<res<<" "<<u<<"\n";
		chk(res,u,u);//cout<<"!!!!! "<<res<<" "<<u<<" "<<chk(res,u,u)<<"\n";
	}
	if(fa[u]){
		int o=ls[fa[u]],v=h[o];
		if(v){
			int ss=sum-f2[u]+1;
			if(ss<k){
				int l=id[v],r=id[ed[top[v]]],res=0;
				while(l<=r){int M=l+r>>1,x=nw[M];if(f1[x]+(f[x]<mid)+ss<=k)res=x,r=M-1;else l=M+1;}
				//cout<<"???????? "<<u<<" "<<o<<" "<<v<<"\n";
				chk(res,u,o);
			}
		}
	}
	//cout<<"END "<<u<<" "<<flag<<"\n";
	for(int v:ve[u])if(v^fa[u]){
		int nsu;
		if(ve[u].size()==1)nsu=0;
		else{
			int p=v==son[u]?son2[u]:son[u],q=fa[u];
			if(f[p]<zf[u])nsu=q;else nsu=p;
		}
		if(fa[u]&&nsu==fa[u])ls[u]=ls[fa[u]];else ls[u]=u;h[u]=nsu,dfs5(v);
	}
}
void dfs6(int u){
	if(fa[u]){
		MX[fa[u]]=u==son[fa[u]]?g[fa[u]]:f[fa[u]],st[++tp]=fa[u],ID[fa[u]]=tp;
		s1[0][tp]=tp+MX[st[tp]],s2[0][tp]=MX[st[tp]]-tp;
		for(int i=1;(1<<i)<=tp;i++)s1[i][tp]=max(s1[i-1][tp],s1[i-1][tp-(1<<i-1)]),s2[i][tp]=max(s2[i-1][tp],s2[i-1][tp-(1<<i-1)]);
	}
	for(auto v:ve2[u]){
		int x=fa[u],y=v[0],p=v[1],id=v[2],ff=1;
		int l=ID[p]+1,r=min(ID[fa[u]],(dep[u]+2*dep[p]-dep[y])/2);
		if(l<=r){
			int k=lg[r-l+1],mx=max(s1[k][r],s1[k][l+(1<<k)-1]);
			ff&=mx-dep[p]+dep[y]-dep[p]<=mid;
		}
		//for(int i=l;i<=r;i++)ff&=i-dep[p]+dep[y]-dep[p]+MX[st[i]]<=mid;
		l=max(r+1,ID[p]+1),r=ID[fa[u]];
		if(l<=r){
			int k=lg[r-l+1],mx=max(s2[k][r],s2[k][l+(1<<k)-1]);
			ff&=mx+dep[u]<=mid; 
		}
		//for(int i=l;i<=r;i++)ff&=dep[u]-i+MX[st[i]]<=mid;
		ans[id]&=ff;
	}
	for(int v:ve[u])if(v^fa[u])dfs6(v);if(fa[u])tp--;
}
bool chk(){
	dfs3(1),dfs4(1,0),flag=m=tp=0;
	for(int i=1;i<=n;i++)ans[i]=1,ve2[i].clear();
	dfs5(1),dfs6(1);for(int i=1;i<=m;i++)flag|=ans[i];return flag;
}
signed main(){
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;for(int i=2;i<=1e6;i++)lg[i]=lg[i>>1]+1;
	while(t--){
		cin>>n>>k,cnt=tp=0;
		for(int i=1;i<=n;i++)ve[i].clear();
		for(int i=1;i<n;i++)cin>>u>>v,ve[u].emplace_back(v),ve[v].emplace_back(u);
		dfs1(1,0),Dfs(1,0),dfs2(1,1);int l=1,r=n/2,res=0;
		while(l<=r){mid=l+r>>1;if(chk())res=mid,r=mid-1;else l=mid+1;}
		cout<<res<<"\n";
	}
}
