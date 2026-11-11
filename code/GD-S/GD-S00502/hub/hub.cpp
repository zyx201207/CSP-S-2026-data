#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
int c,T,n,K,x,y;
vector<int>v[N],ver[2];
int ex[N],ey[N],op[N];
int dep[N],mxd[N][2],fr[N],f[N];
void pre(int u,int fa,int o){
	mxd[u][0]=dep[u];
	mxd[u][1]=0,ver[o].push_back(u);
	op[u]=o;
	for(int to:v[u])
	  	if(to!=fa){
	  		dep[to]=dep[u]+1,pre(to,u,o);
	  		if(mxd[to][0]>mxd[u][0]) mxd[u][0]=mxd[to][0],fr[u]=to;
	  		else if(mxd[to][0]>mxd[u][1]) mxd[u][1]=mxd[to][0];
	  	}
}
int gt,dfu,dfn[N],len[N];
int dis[199][199],Lx[N],Rx[N];
void Dfs(int u,int fa,int rt){
	for(int to:v[u])
	  if(to!=fa)
	    dis[rt][to]=dis[rt][u]+1,Dfs(to,u,rt);
}
void dfs(int u,int fa,int R){
	Lx[u]=++dfu;
	for(int to:v[u]){
		if(to==fa) continue;
		len[to]=max((fr[u]!=to?mxd[u][0]:mxd[u][1])+1,len[u]+1);
		dfs(to,u,R);
		if(mxd[to][0]-dep[u]>R) f[u]+=f[to];
	}
	Rx[u]=dfu;
	if(mxd[u][0]-dep[u]==R||f[u]) f[u]++;
}
bool check(int R){
	for(int i=1;i<n;i++){
		int gs=n+1;
		dfu=0;
		pre(ex[i],ey[i],0);
		dfs(ex[i],ey[i],R);;
		pre(ey[i],ex[i],1);
		dfs(ex[i],ey[i],R);
		for(int u:ver[0])
		  for(int vv:ver[1])
		    for(int k=1;k<=n;k++){
		    	int fl=0;
		    	if(dis[k][u]<=R||dis[k][vv]<=R) fl=1;
		    	if(op[k]==0){
		    		if(Lx[u]<=k&&k<=Rx[u]) fl=1;
				}
				if(op[k]==1){
		    		if(Lx[vv]<=k&&k<=Rx[vv]) fl=1;
				}
				if(fl) gs=min(gs,max(f[u],1)+max(f[vv],1));
			}
		if(gs<=R) return 1;
	}
	return 0;
}
namespace subt{
	int chs[N];
	void brute(){
		int ans=n;
		for(int i=0;i<(1<<n);i++){
			int cnte=0,cntv=0;
			for(int j=1;j<=n;j++)
				if((i>>(j-1))&1){
					chs[j]=1;
					cntv++;
				}
				else chs[j]=0;
			for(int j=1;j<n;j++)
			  if(chs[ex[j]]==1&&chs[ey[j]]==1) cnte++;
//			cout<<i<<":"<<cntv<<" "<<cnte<<endl;
			if(cntv-cnte<=2&&cntv<=K){
				int res=0;
				for(int x=1;x<=n;x++){
					int dd=n+1;
					for(int y=1;y<=n;y++)
					  if(chs[y]) dd=min(dd,dis[x][y]);
					res=max(res,dd);
				}
				ans=min(ans,res);
			}
		}
		cout<<ans<<endl;
	}
};
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>K;
		for(int i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
			ex[i]=x,ey[i]=y;
		}
		for(int i=1;i<=n;i++)
		  dis[i][i]=0,Dfs(i,0,i);
		if(c<=3){
			subt::brute();
			for(int i=1;i<=n;i++) v[i].clear();
			continue;
		}
		int L=0,R=n,res=n;
		while(L<=R){
			int mid=(L+R)>>1;
			if(check(mid)) res=mid,R=mid-1;
			else L=mid+1;
		}
		cout<<res<<endl;
		for(int i=1;i<=n;i++) v[i].clear();
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
