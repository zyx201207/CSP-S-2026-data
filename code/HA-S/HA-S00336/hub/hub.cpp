#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int c,t,d[N][N],hd[N],ver[2*N],nxt[2*N],idx,maxp[N],K,n,m,sum;
void add(int u,int v){
	ver[++idx]=v;
	nxt[idx]=hd[u];
	hd[u]=idx;
}
void dfs(int p,int fa,int u){
	for(int i=hd[p];i;i=nxt[i]){
		int v=ver[i];
		if(v==fa) continue;
		d[u][v]=d[u][p]+1;
		dfs(v,p,u);
	}
}
void calc(int p,int x,int y,int fa){
	maxp[p]=min(d[p][x],d[p][y]);
	for(int i=hd[p];i;i=nxt[i]){
		int v=ver[i];
		if(v==fa) continue;
		maxp[p]=max(maxp[v],maxp[p]);
	}
	sum+=(maxp[p]-min(d[p][x],d[p][y])>=K);
}
bool judge(int x){
	K=x;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
		sum=0;
		calc(x,i,j,0);
		if(sum<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		idx=0;
		for(int i=1;i<=n;i++){
			hd[i]=maxp[i]=0;
			for(int j=1;j<=n;j++) d[i][j]=0;
		}
		cin>>n>>m;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			add(u,v),add(v,u);
		}
		for(int i=1;i<=n;i++) dfs(i,0,i);
		int l=1,r=n;
		while(l<r){
			int mid=l+r>>1;
			if(judge(mid)) r=mid;
			else l=mid+1;
		}
		cout<<l<<'\n';
	}
	return 0;
}

