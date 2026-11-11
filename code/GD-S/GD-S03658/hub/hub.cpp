#include<cstdio>
#include<algorithm>
using namespace std;
template<typename T>
void read(T &x){
	char ch=getchar();bool fg=0;x=0;
	while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	if(ch=='-') fg=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x=(fg?-x:x);
	return ;
}
const int inf=1e9;
int n,m,k,z,x,s,y,ans;
int deg[1000005];
int de[1000005],t,w;
int fa[1000005],dep[1000005];
struct edge{
	int x,y;
}bn[1000005];
int em,e[2000005],nx[2000005],lt[1000005];
void in(int xx,int yy){
	e[++em]=yy,nx[em]=lt[xx],lt[xx]=em;
	return ;
}
void get_len(int xx,int dep,int fa,int &pt,int &mdep){
	if(dep>mdep) pt=xx,mdep=dep;
	for(int i=lt[xx];i!=0;i=nx[i]){
		if(e[i]==fa) continue;
		get_len(e[i],dep+1,xx,pt,mdep);
	}
	return ;
}
void dfs(int xx){
	for(int i=lt[xx];i!=0;i=nx[i]){
		if(e[i]==fa[xx]) continue;
		fa[e[i]]=xx,dep[e[i]]=dep[xx]+1;
		dfs(e[i]);
	}
	return ;
}
void res(int xx){
	for(int i=lt[xx];i!=0;i=nx[i]){
		if(e[i]==fa[xx]) continue;
		deg[xx]++,fa[e[i]]=xx,dep[e[i]]=dep[xx]+1;
		res(e[i]);
	}
	return ;
}
int get_rt(int pt){
	int u=pt,len=0;
	get_len(pt,0,0,u,len);
	int v=u;len=0;
	get_len(u,0,0,v,len);
	fa[u]=0,dep[u]=0;
	dfs(u);
	u=v;
	for(int i=1;i<=dep[v]/2;i++)
		u=fa[u];
	return u;
}
void solve(int id){
	for(int i=1;i<=n;i++) lt[i]=0,deg[i]=0;
	em=0;
	for(int i=1;i<n;i++){
		if(i==id) continue;
		in(bn[i].x,bn[i].y);
		in(bn[i].y,bn[i].x);
	}
	int rtx=get_rt(bn[id].x);
	int rty=get_rt(bn[id].y);
	dep[rtx]=0,dep[rty]=0;
	fa[rtx]=0,fa[rty]=0;
	res(rtx),res(rty);
	t=0,w=0;
	for(int i=1;i<=n;i++){
		if(deg[i]==0) de[++w]=i;
	}
	int sum=n,lmt=w,cnt=0;
	while(t<w){
		++cnt;
		while(t<lmt){
			t++;
			if(de[t]==rtx||de[t]==rty) continue;
			deg[fa[de[t]]]--,sum--;
			if(deg[fa[de[t]]]==0)
				de[++w]=fa[de[t]];
		}
		if(sum<=k) ans=min(ans,cnt);
		lmt=w;
	}
	return ;
}
void work(){
	ans=inf;
	read(n),read(k);
	for(int i=1;i<n;i++)
		read(bn[i].x),read(bn[i].y);
	if(k==n){
		printf("%d\n",n);
		return ;
	}
	for(int i=1;i<n;i++)
		solve(i);
	printf("%d\n",ans);
	return ;
}
int main(){
	//hub
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int tid,tz;
	read(tid),read(tz);
	while(tz--) work();
	return 0;
}