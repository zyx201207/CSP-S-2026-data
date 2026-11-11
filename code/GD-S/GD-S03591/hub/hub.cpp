#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define ll long long 
char Begin;
using namespace std;
int read(){
	int num=0;
	char ch;ch=getchar();
	while(ch<48||ch>57)ch=getchar();
	while(ch>47&&ch<58){
		num=(num<<1)+(num<<3)+(ch^48);
		ch=getchar();
	}return num;
}
const int N=4e6+15;
int tid,n,m,rt,Rt;
vector<int>e[N];
int mx[N],d[N],up[N];
int p[N][25],lo[N],pw[25];
int dfn[N],cnt,fir[N];
int u,v,dfa,dep[N];
int ask(int l,int r){
	l=fir[l],r=fir[r];
	if(l>r)l^=r^=l^=r;
	int x=lo[r-l+1];
	int u=p[l][x],v=p[r-pw[x]+1][x];
	return dep[u]<dep[v]?u:v;
}
void dg0(int x,int fa){
	mx[x]=x,d[x]=0,up[x]=fa;
	dep[x]=dep[fa]+1;
	for(int i:e[x]){
		if(i==fa)continue;
		dg0(i,x);
		if(dfa<d[i]+d[x]+1){
			dfa=d[i]+d[x]+1;
			u=mx[i],v=mx[x];
		}
		if(d[x]<d[i]+1){
			d[x]=d[i]+1;
			mx[x]=mx[i];
		}
	}
}
void dg1(int x,int fa){
	dfn[++cnt]=x,fir[x]=cnt;
	up[x]=fa,dep[x]=dep[fa]+1;
	for(int i:e[x]){
		if(i==fa)continue;
		dg1(i,x);
		dfn[++cnt]=x;
	}
}
bool bz[N];int f[N];
void dg2(int x,int fa,int X){
	f[x]=bz[x]=0;
	int mn=1e9,mx=0;
	for(int i:e[x]){
		if(i==fa)continue;
		dg2(i,x,X);
		mn=min(f[i]+1,mn);
		mx=max(f[i]+1,mx);
	}
	mn=-mn;
	if(mn>=mx)f[x]=-mn;
	else{
		if(mx==X)f[x]=-X-1,bz[x]=1;
		else f[x]=mx;
	}
}
vector<int>V1,V2;
int st[N],tp,sz[N],Mx;
bool vis[N];
vector<int>E[N];
bool cmp(int x,int y){return fir[x]<fir[y];}
void dg3(int x,int fa,int dp){
	Mx=max(Mx,dp);
	for(int i:e[x]){
		if(i==fa)continue;
		if(bz[i])continue;
		if(vis[i])continue;
		dg3(i,x,dp+1);
	}
}
struct Node{int l,r;}A[N];
bool operator<(Node x,Node y){return x.l>y.l;}
int F[N],G[N];
bool chk(int x){
	fr(i,1,n)E[i].clear(),sz[i]=0,f[i]=bz[i]=vis[i]=0;
	dg2(Rt,0,x),rt=0;
	if(f[Rt]>0)bz[Rt]=1;
	fr(i,1,n)if(bz[i])rt=i;
	fr(i,1,n)if(bz[i])rt=ask(rt,i);
	int S=0,mx=0;
	fr(i,1,n)if(bz[i]){
		int u=up[i];
		while(dep[u]>=dep[rt]&&!bz[u])
			bz[u]=1,u=up[u];
	}
	fr(i,1,n)if(bz[i]){S++;for(int t:e[i])sz[t]++;}
	fr(i,1,n){
		if(!bz[i])continue;
		if(sz[i]!=2)continue;
		if(vis[i])continue;
		V1.clear(),V2.clear();
		V1.push_back(i);
		V2.push_back(i);
		for(int t:e[i]){
			if(!bz[t])continue;
			if(sz[t]!=2)continue;
			if(vis[t])continue;
			if(V1.size()==1)V1.push_back(t);
			else V2.push_back(t);
		}
		if(V1.size()>1){
			int up=i;
			while(1){
				bool flag=0;
				int now=V1.back();
				for(int t:e[now]){
					if(!bz[t])continue;
					if(sz[t]!=2)continue;
					if(vis[t])continue;
					if(t==up)continue;
					flag=1,V1.push_back(t);
					break;
				}up=now;
				if(!flag)break;
			}
		}
		if(V2.size()>1){
			int up=i;
			while(1){
				bool flag=0;
				int now=V2.back();
				for(int t:e[now]){
					if(!bz[t])continue;
					if(sz[t]!=2)continue;
					if(vis[t])continue;
					if(t==up)continue;
					flag=1,V2.push_back(t);
					break;
				}up=now;
				if(!flag)break;
			}
		}
		reverse(V1.begin(),V1.end());
		reverse(V2.begin(),V2.end());
		V1.pop_back();
		while(!V2.empty()){
			V1.push_back(V2.back());
			V2.pop_back();
		}
		for(int t:V1)vis[t]=1;
		int SZ=V1.size();
		int u=1,v=SZ;
		for(int t:V1){
			Mx=0;dg3(t,0,0);
			A[u]={u+Mx,v+Mx};
			u++,v--;
		}
		stable_sort(A+1,A+1+SZ);
		fr(t,1,SZ){
			F[t]=max(F[t-1],A[t].l);
			G[t]=max(G[t-1],A[t].r);
		}
		mx=SZ;
		for(int t=0,h=SZ;t<=SZ;t++){
			while(h&&A[h].l-x<=t)h--;
			mx=min(mx,t+max(0,G[h]-x));
		}
		mx=SZ-mx;
		if(S-mx<=m)return 1;
	}
	return S<=m;
}
int tt;
void work(){
	n=read(),m=read(),cnt=0;
	fr(i,1,n){
		e[i].clear();
		dep[i]=up[i]=0;
		mx[i]=d[i]=0;
		fir[i]=0;
	}
	fr(i,2,n){
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(n==m){printf("0\n");return;}
	dfa=u=v=0;dg0(1,0);
	Rt=(dep[u]<dep[v]?v:u);
	fr(i,1,dfa/2)Rt=up[Rt];
	cnt=0;dg1(Rt,0);
	fr(i,1,cnt)p[i][0]=dfn[i];
	fr(k,1,20)fr(i,1,cnt){
		int u=p[i][k-1],v=p[i+pw[k-1]][k-1];
		p[i][k]=(dep[u]<dep[v]?u:v);
	}
	int l=1,r=n-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(chk(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",l);
}
char End;
int main(){
	cerr<<(&End-&Begin)/1024/1024<<endl;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	lo[0]=-1;fr(i,0,20)pw[i]=1<<i;
	fr(i,1,1e6)lo[i]=lo[i>>1]+1;
	tid=read();int Q=read();
	while(Q--)work();
}