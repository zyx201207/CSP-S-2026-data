#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c,T,n,k,lst[N],ans,fans,d[N],fst[N],cnt;
vector<int>e[N];
void dfs(int u,int fa,int vis){
	lst[u]=d[u];
	if((1<<(u-1))&vis){
		fst[u]=d[u];
		if((1<<(fa-1))&vis)cnt--;
	}
	else if(fa){
		fst[u]=fst[fa];
	}
	else{
		fst[u]=-0x3f3f3f3f;
	}
	if(e[u].size()<=1&&fa){
		if((1<<(u-1))&vis)lst[u]=d[u];
		else lst[u]=0x3f3f3f3f;
		ans=max(ans,min(lst[u]-d[u],d[u]-fst[u]));
		return;
	}
	for(int v:e[u]){
		if(v==fa)continue;
		d[v]=d[u]+1;
		dfs(v,u,vis);
		lst[u]=max(lst[u],lst[v]);
	}
	if((1<<(u-1))&vis)lst[u]=d[u];
	ans=max(ans,min(lst[u]-d[u],d[u]-fst[u]));
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		fans=0x3f3f3f3f;
		for(int i=1;i<=(1<<n)-1;i++){
			if(__builtin_popcount(i)!=k)continue;
			cnt=k;
			d[1]=1;ans=0;
			dfs(1,0,i);
			if(cnt<=2)fans=min(fans,ans);
		}
		cout<<fans<<'\n';
	}
}
