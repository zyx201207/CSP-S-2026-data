#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 1e6+6;
const int maxn= 1e9+9;
int c,T,n,k;
int u,v;
vector<int>e[N];
int rt,dep[N],dson[N],f[N];
void build(){
	rt=0;
	for(int i=1;i<=n;i++){
		dep[i]=f[i]=0;
		e[i].clear();
	}
}
void dfs(int p,int fa){
	dep[p]=1;
	dson[p]=p;
	f[p]=fa;
	for(int i=0;i<e[p].size();i++){
		int v=e[p][i];
		if(v==fa)continue;
		dfs(v,p);
		if(dep[v]+1>dep[p]){
			dep[p]=dep[v]+1;
			dson[p]=dson[v];
		}
	}
}
void getrt(){
	int sec=0;
	for(int i=0;i<e[1].size();i++){
		int v=e[1][i];
		if(dep[v]>sec&&dson[v]!=dson[1]){
			sec=dep[v];
		}
	}
	int dp=dep[1]+sec+1;
	dp/=2;
	rt=dson[1];
	for(int i=1;i<dp;i++){
		rt=f[rt];
	}
}
int maxl;
int cal(int p,int fa,int mdep){
	if(dep[p]==mdep+2)return 1;
	if(dep[p]<=mdep+1)return 0;
	int re=0;
	if(p==rt){
		int re2=0,nw=0,cntt=0;
		for(int i=0;i<e[p].size();i++){
			if(e[p][i]==fa)continue;
			nw=cal(e[p][i],p,mdep);
			if(nw>re)re=nw;
			else if (nw>re2)re2=nw;
			if(dep[e[p][i]]>mdep)cntt++;
		}
		if(cntt<=2){
			maxl=max(maxl,re+re2);
		}
	}else{
		int cntt=0;
		for(int i=0;i<e[p].size();i++){
			if(e[p][i]==fa)continue;
			re=max(re,cal(e[p][i],p,mdep));
			if(dep[e[p][i]]>mdep)cntt++;
		}
		if(cntt<=2){
			maxl=max(maxl,re+1);
			return re+1;
		}else{
			return 0;
		}
	}
	return 0;
}
bool check(int mdep){
	maxl=1;
	cal(rt,0,mdep);
	if(maxl>2*mdep)maxl=2*mdep;
	maxl--;
	int ans=n;
	ans-=maxl;
	for(int i=1;i<=n;i++){
		if(dep[i]<=mdep)ans--;
	}
//	cerr<<ans<<' '<<mdep<<' '<<maxl<<'\n';
	if(ans<=k)return 1;
	return 0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		build();
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1,0);
		getrt();
		dfs(rt,0);
		int l=0,r=n;
		while(r>l+1){
			int mid=(l+r)>>1;
			if(check(mid)){
				r=mid;
			}else{
				l=mid;
			}
		}
//		cerr<<rt<<'\n';
		if(n==k){
			cout<<"0\n";
			continue;
		}
		cout<<r<<'\n';
	}
}
