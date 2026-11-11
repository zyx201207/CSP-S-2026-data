#include<bits/stdc++.h>
using namespace std;
namespace MYQ{
	const int N=1000006;
	int t,n,m,h[N],mh[N],fa[N],f[N],no,so[N],gg[N],gh[N];
	basic_string<int>b[N];
	void dfs(int x,int y){
		h[x]=h[y]+1;
		fa[x]=y;
		mh[x]=h[x];
		int sx=h[x];
		so[x]=0;
		for(int i:b[x])
			if(i!=y){
				dfs(i,x);
				if(mh[i]>mh[x])
					sx=mh[x],mh[x]=mh[i];
				else
					sx=max(sx,mh[i]);
				if(so[x]==0||mh[so[x]]<mh[i])
					so[x]=i;
			}
		for(int i:b[x])
			if(i!=y){
				if(mh[i]==mh[x])
					gh[i]=sx;
				else
					gh[i]=mh[x];
			}
	}
	void df1(int x,int y){
		f[x]=1;
		for(int i:b[x]) 
			if(i!=y){
				df1(i,x);
				if(mh[i]-h[x]>no)
					f[x]+=f[i];
			}
	}
	int *g[N];
	int tmg[N<<1],ng,mxg[N];
	int *hh[N];
	int tmh[N<<1],nh,mxh[N],mih[N];
	int *u[N];
	int tmu[N<<1],nu,mxu[N];
	void df2(int x,int y){
		g[x]=&tmg[ng];
		ng++;
		hh[x]=&tmh[nh];
		nh++;
		u[x]=&tmu[nu];
		nu++;
		gg[x]=f[x];
		if(so[x]){
			df2(so[x],x);
			mxg[x]=mxg[so[x]];
			mih[x]=mih[so[x]];
			mxh[x]=mxh[so[x]];
			if(mh[so[x]]-h[x]>no)
				gg[x]=min(gg[x],f[x]-f[so[x]]+gg[so[x]]);
		}
		else{
			mxg[x]=mh[x];
			mxh[x]=mh[x];
			mih[x]=mh[x];
		}
		g[x][0]=f[x];
		u[x][0]=gg[x];
		while(mxg[x]-h[x]>no){
			g[x][mxg[x]-h[x]]=1e9;
			mxg[x]--;
		}
		while(mxu[x]-h[x]>no){
			u[x][mxu[x]-h[x]]=1e9;
			mxu[x]--;
		}
		int mxx=h[x];
		for(int i:b[x])
			if(i!=so[x]&&i!=y){
				df2(i,x);
				for(int j=h[i];j<=mh[i]&&j+mh[x]-h[x]*2<=no;j++)
					g[x][j-h[x]]=min(g[x][j-h[x]],g[i][j-h[i]]);
				while(mxg[x]+mh[i]-h[x]*2>no){
					g[x][mxg[x]-h[x]]=1e9;
					mxg[x]--;
				}
				for(int j=h[i];j<=mh[i]&&j+mh[x]-h[x]*2<=no;j++)
					u[x][j-h[x]]=min(u[x][j-h[x]],u[i][j-h[i]]);
				while(mxu[x]+mh[i]-h[x]*2>no){
					u[x][mxu[x]-h[x]]=1e9;
					mxu[x]--;
				}
				for(int j=mih[i];j<=mxh[i];j++){
					hh[x][mh[x]-h[x]]=min(hh[x][mh[x]-h[x]],hh[i][j-h[i]]);
					mxh[x]=mh[x];
				}
				if(mh[i]-h[x]>no)
					gg[x]=min(gg[x],f[x]-f[i]+gg[i]);
				mxx=max(mxx,h[i]);
			}
			while(mih[x]<mxx){
				hh[x][mxx-h[x]]=min(hh[x][mih[x]-h[x]],hh[x][mxx-h[x]]);
				hh[x][mih[x]-h[x]]=1e9;
				mih[x]++;
			}
		while(mxg[x]+gh[x]-2*(h[x]-1)>no){
			hh[x][0]=min(hh[x][0],g[x][mxg[x]-h[x]]);
			g[x][mxg[x]-h[x]]=1e9;
			mxg[x]--;
		}
		while(mxu[x]+gh[x]-2*(h[x]-1)>no){
			u[x][mxu[x]-h[x]]=1e9;
			mxu[x]--;
		}
		while(mxh[x]>=mih[x]&&(mxh[x]-(h[x]-1)>no||gh[x]-h[x]>no)){
			if(mh[x]-(h[x]-1)>no)
				gg[fa[x]]=min(gg[fa[x]],f[fa[x]]-f[x]+hh[x][mxh[x]-h[x]]);
			else
				gg[fa[x]]=min(gg[fa[x]],f[fa[x]]+hh[x][mxh[x]-h[x]]);
			hh[x][mxh[x]-h[x]]=1e9;
			mxh[x]--;
		}
	}
	inline bool ck(int x){
		no=x;
		for(int i=1;i<=n;i++)
			f[i]=1e9,gg[i]=1e9;
		df1(1,0);
		for(int i=1;i<=n*2;i++)
			tmg[i]=1e9;
		ng=1;
		for(int i=1;i<=n*2;i++)
			tmh[i]=1e9;
		nh=1;
		for(int i=1;i<=n*2;i++)
			tmu[i]=1e9;
		nu=1;
		df2(1,0);
		for(int i=h[1];i<=mxh[1];i++)
			if(hh[1][i-h[1]]<=m)
				return 1;
		for(int i=h[1];i<=mxg[1];i++)
			if(g[1][i-h[1]]<=m)
				return 1;
		if(gg[1]<=m)
			return 1;
		for(int i=h[1];i<=mxu[1];i++)
			if(u[1][i-h[1]]<=m)
				return 1;
		return 0;
	}
	int main(){
		scanf("%*d%d",&t);
		while(t--){
			scanf("%d%d",&n,&m);
			for(int i=1;i<=n;i++)
				b[i].clear();
			for(int i=1;i<n;i++){
				int x,y;
				scanf("%d%d",&x,&y);
				b[x].push_back(y);
				b[y].push_back(x);
			}
			dfs(1,0);
			if(m>=n){
				printf("0\n");	
				continue;
			}
			int l=1,r=n-1,mid,an;
			while(l<=r){
				mid=l+r>>1;
				if(ck(mid)==1)
					an=mid,r=mid-1;
				else
					l=mid+1; 
			}
			printf("%d\n",an);
		}
		return 0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	MYQ::main();
	return 0;
}
