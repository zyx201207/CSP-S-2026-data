#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int hd[N];
struct edge{
	int to,v,nxt;
}e[N];
int idx;
int w[N];
int a[N][N],t[N][N],l[N],s[N][N];
void add(int u,int v,int w){
	e[++idx]={v,w,hd[u]};
	hd[u]=idx;
}
int res=0x3f3f3f3f;
int st,ed;
void dfs(int x,int p,int cnt){
	if(x==ed){
		res=min(res,cnt+s[p][ed]);
		return;
	}
	for(int i=hd[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(e[i].v!=p){
			dfs(y,e[i].v,cnt+s[p][x]+s[e[i].v][x]);
		}else{
			dfs(y,p,cnt);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		l[i]=x;
		for(int j=1;j<=x;j++){
			cin>>a[i][j];

			cin>>t[i][j];
						s[i][a[i][j]]=t[i][j];
		}
		for(int j=2;j<=x;j++){
			add(a[i][j-1],a[i][j],i);
		}
	}
	while(q--){
		res=0x3f3f3f3f;
		cin>>st>>ed;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=l[i];j++){
				if(a[i][j]==st)dfs(st,i,w[st]+w[ed]+s[i][st]);
			}
		}
		cout<<res<<'\n';
	}
	return 0;
}
