#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,INF=1e9;
vector<int>b[N];
int n,k,ans,vi[N],fa[N],dep[N],pre[N];
int dfs2(int x,int p){
	int res=x,pr=vi[x];
	vi[x]=p;
	dep[x]=0;
	for(auto i:b[x]){
		if(vi[i]==p) continue;
		pre[i]=x;
		int y=dfs2(i,p);
		if(dep[i]+1>dep[x]){
			dep[x]=dep[i]+1;
			res=y;
		}
	}
	vi[x]=pr;
	return res;
}
int dfs3(int x,int p,int dis){
	int res=0,pr=vi[x];
	vi[x]=p;
	dep[x]=0;
	for(auto i:b[x]){
		if(vi[i]==p) continue;
		res+=dfs3(i,p,dis);
		if(dep[i]+1>dep[x]){
			dep[x]=dep[i]+1;
		}
	}
	if(dep[x]>=dis){
		res++;
	}
	vi[x]=pr;
	return res;
}
int calc(int x){
	int L=0,R=n;
	while(L<R){
		int mid=(L+R)>>1,cnt=0;
		int rt=dfs2(x,1);
		int y=dfs2(rt,1);
		for(int i=1;i<=dep[rt]/2;i++){
			y=pre[y];
		}
		cnt+=dfs3(y,1,mid);
		vi[x]=2;
		rt=dfs2(fa[x],2);
		y=dfs2(rt,2);
		for(int i=1;i<=dep[rt]/2;i++){
			y=pre[y];
		}
		cnt+=dfs3(y,2,mid);
		if(cnt<=k) R=mid;
		else L=mid+1;
		vi[x]=0;
	}
	return L;
}
void dfs1(int x){
	if(x!=1){
		ans=min(ans,calc(x));
	}
	vi[x]=1;
	for(auto i:b[x]){
		if(vi[i]) continue;
		fa[i]=x;
		dfs1(i);
	}
	vi[x]=0;
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		ans=INF;
		for(int i=1;i<=n;i++){
			b[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			b[u].push_back(v);
			b[v].push_back(u);
		}
		dfs1(1);
		cout<<ans<<'\n';
	}
}
