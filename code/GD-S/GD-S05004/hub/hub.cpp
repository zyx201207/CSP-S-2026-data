#include<bits/stdc++.h>
#define FL(i,a,b) for(int i=(a);i<=(b);i++)
#define FR(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long
using namespace std;

const int MAXN = 1e6 + 10;

int n,K;
int P,Q;
int dP[MAXN],prv[MAXN];
int L,a[MAXN],mx[MAXN];
vector<int>G[MAXN];
bool vs[MAXN],us[MAXN];

void dfs1(int u,int fth,int d){
	if(d>L) L=d,P=u;
	for(int v:G[u]){
		if(v==fth) continue;
		dfs1(v,u,d+1);
	}
}
void dfs2(int u,int fth){
	if(dP[u]>L) L=dP[u],Q=u;
	for(int v:G[u]){
		if(v==fth) continue;
		prv[v]=u,dP[v]=dP[u]+1,dfs2(v,u);
	}
}
void dfs3(int u,int fth){
	mx[u]=0;
	for(int v:G[u]){
		if(v==fth||vs[v]) continue;
		// printf("%d -> %d\n",u,v);
		dfs3(v,u);
		mx[u]=max(mx[u],mx[v]+1);
	}
}

int tg[MAXN];
int f[MAXN],g[MAXN];

bool check(int mid){
	int tot=0,ttr=0,res=n;
	FL(i,1,n) us[i]=(mx[i]>=mid),tot+=us[i],ttr+=(us[i]&&!vs[i]);
	if(tot>=K) return 0;
	int nL=-1,nR=-1;
	FL(i,1,L) tg[i]=0;
	FL(i,1,L){
		if(nL==-1&&tg[i]) tg[i]=0,nL=nR=i;
		if(nL==-1&&us[a[i]]) nL=nR=i;
		if(us[a[i]]) nR=max(nR,i);
		// printf("i=%d,nL=%d,nR=%d\n",i,nL,nR);
		assert(nL==-1||(nL<=nR&&nR<=i));
		int tL=-1,tR=-1;
		if(!us[a[i]]&&nL==-1){
			int d=mid-mx[a[i]];
			assert(d>0);
			tg[min(i+d,L)]++;
			tL=i,tR=i;
		}
		else if(!us[a[i]]){
			int d=mid-mx[a[i]];
			assert(d>0);
			if(nL!=-1&&i-d<=nR) tL=nL,tR=nR;
			else nR=i-d,tL=nL,tR=nR;
		}
		else if(us[a[i]]) tL=nL,tR=nR;
		// printf("i=%d,nL=%d,nR=%d\n",i,nL,nR);
		assert(tL!=-1&&tR!=-1);
		f[i]=tR-tL+1;
	}
	nL=nR=-1;
	FL(i,1,L) tg[i]=0;
	FR(i,L,1){
		if(nR==-1&&tg[i]) tg[i]=0,nL=nR=i;
		if(nR==-1&&us[a[i]]) nL=nR=i;
		if(us[a[i]]) nL=min(nL,i);
		assert(nR==-1||(nL<=nR&&nL>=i));
		int tL=-1,tR=-1;
		if(!us[a[i]]&&nR==-1){
			int d=mid-mx[a[i]];
			assert(d>0);
			tg[max(i-d,1)]++;
			tL=i,tR=i;
		}
		else if(!us[a[i]]){
			int d=mid-mx[a[i]];
			assert(d>0);
			if(nR!=-1&&i+d>=nL) tL=nL,tR=nR;
			else nL=i+d,tL=nL,tR=nR;
		}
		else if(us[a[i]]) tL=nL,tR=nR;
		assert(tL!=-1&&tR!=-1);
		g[i]=tR-tL+1;
	}
	f[0]=g[L+1]=0;
	FL(i,0,L) res=min(res,f[i]+g[i+1]+ttr);
	return (res<=K); 
}

void Solve(){
	scanf("%d%d",&n,&K);
	FL(i,1,n) G[i].clear(),vs[i]=0;
	FL(i,1,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	L=-1,P=-1,dfs1(1,0,0),assert(P!=-1);
	L=-1,Q=-1,dP[P]=prv[P]=0,dfs2(P,0),assert(Q!=-1);
	// printf("P=%d,Q=%d\n",P,Q);
	// FL(i,1,n) printf("dP[%d]=%d\n",i,dP[i]);
	int nw=Q;L=0;
	while(nw)
		a[++L]=nw,vs[nw]=1,nw=prv[nw];
	// FL(i,1,L) printf("%d ",a[i]);
	// puts("");
	FL(i,1,L){
		int u=a[i];
		dfs3(u,0);
	}
	// FL(i,1,n) printf("mx[%d]=%d\n",i,mx[i]);
	int l=0,r=L-1,ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	assert(ans!=-1);
	printf("%d\n",ans);
	return ;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int ID,Num;
	scanf("%d%d",&ID,&Num);
	while(Num--) Solve();
	return 0;
}
