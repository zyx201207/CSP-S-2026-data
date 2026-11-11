/*
-fsanitize=address,undefined

ios::sync_with_studio(0);
cin.tie(0);

cout<<fixed<<precision();

先想到15:24 

目前24pts，不好写 

来不及了，30pts 

- 找直径 
- 直径上预处理出dep
- 对dep+-i做st表 
- 两边各自树上背包 
然后k^2背包合并
*/
#include <bits/stdc++.h>
#define ll long long
#define FOR(i,l,r) for(int i=(l);i<=(r);++i)
#define ROF(i,r,l) for(int i=(r);i>=(l);--i)
#define pii pair<int,int>
#define mkp make_pair
#define fir first
#define sec second
using namespace std;

namespace mycode{
	const int MAXN=1e3+5;
	const int MAXK=1e3+5;
	const int inf=1e9;
	int f[MAXN][MAXK];
	
	int dep[MAXN],fa[MAXN],siz[MAXN],stk[MAXN],top=0,k;
	bitset<MAXN> inzhijing;
	vector<int> G[MAXN];
	int K[2][MAXN][MAXK];//两个方向的树上背包 
	int n;
	
	void dfs1(int x){//第一遍 
		dep[x]=dep[fa[x]]+1;
		for(int v:G[x]){
			if(v==fa[x]) continue; 
			fa[v]=x,dfs1(v);
		}
	}
	
	int tmp[MAXK];
	void dfs(int x,int F){
		siz[x]=1;
		FOR(i,0,k) f[x][i]=inf;
		f[x][0]=1;//无则+1
		f[x][1]=0;
		for(int v:G[x]){
			if(v==F) continue;
			dfs(v,x);
			f[x][0]=max(f[x][0],f[v][0]+1);
			FOR(i,1,k) tmp[i]=f[x][i],f[x][i]=inf;
			FOR(i,1,min(siz[x],k)){
				FOR(j,0,min(siz[v],k)){
					if(i+j>k) break;
					f[x][i+j]=min(f[x][i+j],max(tmp[i],f[v][j]));
				}
			}
			siz[x]+=siz[v];
		}
	}//树上背包 
	
	int dfsdep(int x,int D,int F){
		int res=D;
		for(int v:G[x]){
			if(inzhijing[v]) continue;
			if(F==v) continue;
			res=max(dfsdep(v,D+1,x),res);
		}
		return res;
	}
	
	struct ST{
		int st[MAXN][15];//st表 
		void build(){
			for(int i=1;(1<<i)<=n;++i)FOR(j,1,n) st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		}
		int query(int l,int r){
			int t=(int)log2(r-l+1);
			return max(st[l][t],st[r-(1<<t)+1][t]);
		}
	}st[2];
	
	void init(){
		FOR(i,1,n) G[i].clear(),G[i].shrink_to_fit();
		FOR(i,1,n) inzhijing[0]=0;
		top=0;
		dep[0]=0;
	}
	
	void work(){
		int ans=0;
		init();
		scanf("%d%d",&n,&k);
		FOR(i,2,n){
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		fa[1]=0;
		dfs1(1);
		int H=0;FOR(i,1,n) fa[i]=0,H=(!H||dep[i]>dep[H])?i:H;
		dfs1(H);
		int p=0;FOR(i,1,n) p=(!p||dep[i]>dep[p])?i:p;
		while(p) stk[++top]=p,inzhijing[p]=1,p=fa[p];
		int c=stk[(top+1)/2];
		dfs(c,c);ans=f[c][k];
		dfs(stk[1],stk[1]);FOR(i,1,top)FOR(j,1,k) K[0][stk[i]][j]=f[stk[i]][j];//向右 
		dfs(stk[n],stk[n]);FOR(i,1,top)FOR(j,1,k) K[1][stk[i]][j]=f[stk[i]][j];//向左 
		FOR(i,1,top){
			int d=dfsdep(stk[i],0,stk[i]);
			st[0].st[i][0]=d+i;
			st[1].st[i][0]=d-i;
		}
		st[0].build();st[1].build();
		FOR(l,1,top)FOR(r,l+1,top){
			int res=inf;
			FOR(i,1,k)FOR(j,1,k){
				if(i+j>k) break;
				res=min(res,max(K[1][stk[l]][i],K[0][stk[r]][j]));
			}
			int L=l+1,R=r-1,mid=(L+R)>>1;
//			printf("[%d,%d](%d)\n",L,R,mid);
			if(L>R) ans=min(ans,res);
			else if(L==R) ans=min(ans,max(res,st[0].st[L][0]-l));
			else ans=min(ans,max({res,st[0].query(L,mid)-l,st[1].query(mid+1,R)+r}));
//			printf("[%d,%d][%d]\n",l,r,ans);
		} 
		printf("%d\n",ans);
	}
	
	int main(){
		int c,T;scanf("%d%d",&c,&T);
		while(T--) work();
		return 0;
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	mycode::main();
	return 0;
}
