#include<bits/stdc++.h>
#define il inline
#define gc getchar
using namespace std;
int res;char ch;
const int N=1000000;
int c,T,n,k,u,v,h[N+5],to[N*2+5],nxt[N*2+5],et=1,fr[N+5],ed[N+5]; 
void adde(int u,int v){
	to[++et]=v;
	nxt[et]=h[u];
	h[u]=et;
}
il int rd(){
	res=0,ch=gc();
	while(ch<'0'||ch>'9') ch=gc();
	while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch&15),ch=gc();
	return res;
}
const int M=4000;
void clr(){
	for(int i=1;i<=n;i++) h[i]=0;
	et=1;
}
int siz[M+5],os[N+5],cur;
int f[M+5][M+5],fmx[N+5],smx[N+5],mx[N+5];
int A[M+5],B[M+5],ans;
void dfs1(int x,int fa){
	os[x]=1;
	for(int i=h[x];i;i=nxt[i]){
		if(to[i]==fa) continue;
		dfs1(to[i],x);
		fr[i/2]=x;
		ed[i/2]=to[i];
		os[x]+=os[to[i]];
	}
}
int t[M+5];
void dfs2(int x,int fa){
	f[x][0]=f[x][1]=0;
	siz[x]=1;
	fmx[x]=smx[x]=-1;
	for(int i=h[x];i;i=nxt[i]){
		if(to[i]==fa) continue;
		dfs2(to[i],x);
		if(f[to[i]][0]>fmx[x]) smx[x]=fmx[x],fmx[x]=f[to[i]][0];
		else if(f[to[i]][0]>smx[x]) smx[x]=f[to[i]][0];
		f[x][0]=max(f[x][0],f[to[i]][0]+1);
		for(int j=1;j<=min(k,siz[x]+siz[to[i]]);j++) t[j]=INT_MAX;
		for(int j=1;j<=min(k,siz[x]);j++)
			for(int l=0;l<=min(k-j,siz[to[i]]);l++)
				t[j+l]=min(t[j+l],max(f[x][j],l==0?f[to[i]][l]+1:f[to[i]][l]));
		for(int j=1;j<=min(k,siz[x]+siz[to[i]]);j++) f[x][j]=t[j];
		siz[x]+=siz[to[i]];
	}
}
void dfs3(int x,int fa){
	for(int i=1;i<=min(k,siz[x]);i++) t[i]=min(t[i],max(f[x][i],mx[x]));
	for(int i=h[x];i;i=nxt[i]){
		if(to[i]==fa) continue;
		if(f[to[i]][0]==fmx[x]) mx[to[i]]=max(mx[x]+1,smx[x]+2);
		else mx[to[i]]=max(mx[x]+1,fmx[x]+2);
		dfs3(to[i],x);
	}
}
void solve(){
	n=rd(),k=rd();
	for(int i=1;i<n;i++){
		u=rd(),v=rd();
		adde(u,v),adde(v,u);
	}
	dfs1(1,0);
	ans=INT_MAX;
	for(int i=1;i<n;i++){
		cur=os[ed[i]];
		for(int j=1;j<=min(k-1,cur);j++) t[j]=INT_MAX;
		mx[ed[i]]=0;
		dfs2(ed[i],fr[i]);
		dfs3(ed[i],fr[i]);
		for(int j=1;j<=min(k-1,cur);j++) A[j]=t[j];
		cur=n-os[ed[i]];
		for(int j=1;j<=min(k-1,cur);j++) t[j]=INT_MAX;
		mx[fr[i]]=0;
		dfs2(fr[i],ed[i]);
		dfs3(fr[i],ed[i]);
		for(int j=1;j<=min(k-1,cur);j++) B[j]=t[j];
		for(int j=max(1,k-n+os[ed[i]]);j<=min(k-1,os[ed[i]]);j++) ans=min(ans,max(A[j],B[k-j]));
	}
	printf("%d\n",ans);
	clr();
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=rd(),T=rd();
	while(T--) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
