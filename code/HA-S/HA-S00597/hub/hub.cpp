#include <bits/stdc++.h>
using namespace std;
const int N=100;
int c,t,cnt,ans=1e9;
int n,m;
int dep[N],fa[N],f[N],ff[N],siz[N],son[N],tp[N];
int head[N];
struct node{
	int to,nxt;
}ed[N];
void dfs0(int x,int ffa){
	fa[x]=ffa;
	dep[x]=dep[ffa]+1;
	siz[x]=1;
	for(int i=head[x];i!=0;i=ed[i].nxt){
		int y=ed[i].to;
		if(y==ffa) continue;
		dfs0(y,x);
		siz[x]+=siz[y];
		if(siz[y]>siz[son[x]]) son[x]=y;
	}
}
void dfs2(int x,int t_p){
	tp[x]=t_p;
	if(son[x]!=0){
		dfs2(son[x],t_p);
	}
	for(int i=head[x];i!=0;i=ed[i].nxt){
		int y=ed[i].to;
		if(y==fa[x]||y==son[x]) continue;
		dfs2(y,y);
	}
}
void add(int x,int y){
	ed[++cnt].nxt=head[x];
	ed[cnt].to=y;
	head[x]=cnt;
}
int LCA(int x,int y){
	while(tp[x]!=tp[y]){
		if(dep[tp[x]]<dep[tp[y]]) swap(x,y);
		x=fa[tp[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	return x;
}
void dfs1(int x){
	ff[x]=1;
	for(int i=head[x];i!=0;i=ed[i].nxt){
		int y=ed[i].to;
		if(f[y]==0||ff[y]==1) continue;
		dfs1(y);
	}
}
void check(){
	int num=0,res=0,mn=0;
	for(int i=1;i<=n;i++) ff[i]=0;
	for(int i=1;i<=n;i++){
		if(ff[i]==0&&f[i]==1){
			if(mn==0) mn=i;
			num++;
			dfs1(i);
		}
	}
	if(num>2) return;
	for(int i=mn+1;i<=n;i++){
		if(f[i]==1){
			res=max(res,dep[mn]+dep[i]-dep[LCA(mn,i)]*2);
		}
	}
	ans=min(res,ans);
}
void dfs(int x){
	if(x==m+1){
		check();
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==1) continue;
		f[i]=1;
		dfs(x+1);
		f[i]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		int x,y;
		ans=1e9;
		cnt=0;
		memset(head,0,sizeof(head));
		for(int i=1;i<n;i++){
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		dfs0(1,0);
		dfs2(1,1);
		dfs(1);
		cout<<ans<<'\n';
	}
}

