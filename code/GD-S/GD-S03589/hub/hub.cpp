#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10,INF=1e9;
int FW,T,n,m,hd[MAXN],to[MAXN<<1],nxt[MAXN<<1],fw,vis[MAXN],Ans,f[MAXN],ans;
void add(int x,int y){
	nxt[++fw]=hd[x];
	to[fw]=y,hd[x]=fw;
}
int Find(int x){
	if(x==f[x]) return x;
	else return f[x]=Find(f[x]);
}
void cl(int x,int fa){
	for(int i=hd[x];i;i=nxt[i]){
		int v=to[i];
		if(v==fa) continue;
		if(vis[v]&&vis[x]) f[Find(v)]=Find(x);
		cl(v,x);
	}
}
int pd(){
	int sum1=0,sum2=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]) continue;
		int x=Find(i);
		if(!sum1) sum1=x;
		else{
			if(sum1!=x){
				if(!sum2) sum2=x;
				else if(sum2!=x) return 1;
			}
		}
	}
	return 0;
}
int js(int x,int fa){
	int sum=0;
	for(int i=hd[x];i;i=nxt[i]){
		int v=to[i];
		if(v==fa) continue;
		sum=max(js(v,x),sum);
	}
	if(vis[x]) Ans=max(Ans,sum),sum=0;
	else ++sum;
	return sum;
}
void dfs(int x,int y){
	if(y>m) return;
	if(x>n){
		if(y!=m) return;
		int id=0;
		for(int i=1;i<=n;i++){
			f[i]=i;
			if(vis[i]) id=i;
		}
		cl(1,0);
		if(pd()) return;
		Ans=0,js(id,0);
		ans=min(ans,Ans);
		return;
	}
	vis[x]=1,dfs(x+1,y+1),vis[x]=0,dfs(x+1,y);
}
int check(int p,int g,int x,int y){
	int G=p-(g-1)*2-x-y;
	return g*2>=G;
}
void work(){
	scanf("%d%d",&n,&m),fw=0;
	for(int i=0;i<=n;i++) hd[i]=0;
	for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	if(m>=n){
		puts("0");
		return;
	}
	if(FW<=3) ans=INF,dfs(1,0),printf("%d\n",ans);
	if(FW==13||FW==14){
		int p=n>>1;
		if(m>=p){
			puts("1");
			return;
		}
		int x=m>>1,y=m-x,L=1,R=p+2;
		while(L<=R){
			int mid=(L+R)>>1;
			if(check(p,mid,x,y)) R=mid-1,ans=mid;
			else L=mid+1;
		}
		printf("%d\n",ans);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&FW,&T);
	while(T--) work();
	return 0;
} 
