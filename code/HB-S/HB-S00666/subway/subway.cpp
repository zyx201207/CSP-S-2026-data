#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e5+5,N=1e3+3;
struct edge{
	int to,line;
};
struct node{
	int cur,line,time;
};
int c,n,m,d,q,w[M],k[N],a[N][M],t[M][N],xr,yr,minn,biao[M];
vector<edge>va[M];
void dfs(int u,int li,int ti){
	if(u==yr){
		minn=min(minn,ti+t[u][li]);
	}
	for(int i=0;i<(int)va[u].size();i++){
		int v=va[u][i].to,vline=va[u][i].line;
		if(!biao[v]){
			biao[v]=1;
			if(vline==li){
				dfs(v,li,ti);
			}
			else{
				dfs(v,vline,ti+t[u][li]+t[u][vline]);
			}
			biao[v]=0;
		}
	}
	
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[a[i][j]][i];
			if(j>1){
				va[a[i][j-1]].push_back({a[i][j],i});
				va[a[i][j]].push_back({a[i][j-1],i});
			}
		}
	}
	while(q--){
		cin>>xr>>yr;
		minn=INT_MAX;
		memset(biao,0,sizeof biao);
		dfs(xr,0,0);
		cout<<minn+w[xr]+w[yr]<<endl;
	}
	return 0;
}
