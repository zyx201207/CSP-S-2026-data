#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define psb push_back
#define mid (l+r>>1)
#define endl '\n'

const int mx=1e6+5;
const ll inf=1e18;
int cs,t,ct,n,m,dep[mx],fa[mx],sn[mx],sz[mx],tp[mx],vs[mx];
ll s;
vector<int>v[mx];

void dfs1(int x,int y){
	dep[x]=dep[y]+1;
	fa[x]=y;
	sn[x]=0;
	sz[x]=1;
	for(int i:v[x]){
		if(i==y) continue;
		dfs1(i,x);
		if(sz[i]>sz[sn[x]]) sn[x]=i;
		sz[x]+=sz[i];
	}
}
void dfs2(int x,int y){
	tp[x]=y;
	if(sn[x]) dfs2(sn[x],y);
	for(int i:v[x]) if(i!=fa[x]&&i!=sn[x]) dfs2(i,i);
}
int lca(int x,int y){
	while(tp[x]!=tp[y]) (dep[tp[x]]>dep[tp[y]]?x=fa[tp[x]]:y=fa[tp[y]]);
	return (dep[x]<dep[y]?x:y);
}
void clc(int x,int y){
	if(vs[x]&&!vs[y]) ct++;
	for(int i:v[x]) if(i!=y) clc(i,x);
}
int dst(int x,int y){
	return dep[x]+dep[y]-dep[lca(x,y)]*2;
}

void slv(){
	cin>>n>>m;
	for(int x,y,i=1;i<n;i++){
		cin>>x>>y;
		v[x].psb(y);
		v[y].psb(x);
	}
	dfs1(1,0);
	dfs2(1,1);
	s=inf;
	for(int i=1;i<(1<<n);i++){
		int y=0;
		for(int j=1;j<=n;j++) y+=(vs[j]=((i>>j-1)&1));
		if(y!=m) continue;
		ct=0;
		clc(1,0);
		if(ct>2) continue;
		ll x=0;
		for(int j=1;j<=n;j++){
			if(!vs[j]) continue;
			ll z=0;
			for(int k=1;k<=n;k++) if(vs[k]) z+=dst(j,k);
			x=max(x,z);
		}
		s=min(s,x);
	}
	cout<<s<<endl;
	for(int i=1;i<=n;i++) v[i].clear();
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>cs>>t;
	while(t--) slv();
	return 0;
}
