#include<bits/stdc++.h>
#define int long long
using namespace std;
int nex[1000010],hed[1000010],to[1000010],num[1000010],cntg;
void add(int u,int v,int numb){
	nex[++cntg]=hed[u];
	to[cntg]=v;
	num[cntg]=numb;
	hed[u]=cntg;
}
int c;
int n,k[510];
vector<int> a[510],t[510];
int tt[100010][510];
int m,w[500010];
int d;
int q,x,y;
int ans;
int vis[500010];
void dfs(int u,int fa,int l,int lastnum){
	vis[u]=1;
	if(u==y){
		ans=min(ans,l+tt[u][lastnum]);vis[u]=0;return ;
	}
	for(int e=hed[u];e;e=nex[e]){
		int v=to[e];
		if(!vis[v]&&v!=fa){
			if(lastnum==num[e])
				dfs(v,u,l,num[e]);
			else
				dfs(v,u,l+tt[u][lastnum]+tt[u][num[e]],num[e]);
		}
	}
	vis[u]=0;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int _,__;
		cin>>_>>__;
		a[i].push_back(_);t[i].push_back(__);
		tt[a[i][0]][i]=t[i][0];
		for(int j=1;j<k[i];j++){
			cin>>_>>__;
			a[i].push_back(_);t[i].push_back(__);
			tt[a[i][j]][i]=t[i][j];
			add(a[i][j-1],a[i][j],i);
			add(a[i][j],a[i][j-1],i);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=LLONG_MAX;
		dfs(x,0,0,0);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
