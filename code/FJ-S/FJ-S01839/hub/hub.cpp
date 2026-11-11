#include<bits/stdc++.h>
#define pb push_back
using namespace std;const int N=1e6+5;
int n,k,cnt,len[N],st[N],last[N],mxlen[N],mid;
vector<int>e[N];
void dfs1(int u,int fa){len[u]=1;
	for(auto v:e[u])if(v!=fa)dfs1(v,u),len[u]=max(len[u],len[v]+1);
	sort(e[u].begin(),e[u].end(),[](int a,int b){return len[a]>len[b];});
}
void dfs(int u,int fa){
	mxlen[u]=1;
	for(auto v:e[u])if(v!=fa)dfs(v,u),mxlen[u]=max(mxlen[u],mxlen[v]+1);
	for(auto v:e[u])if(v!=fa){
		if(mxlen[v]>=mid)st[u]=1,cnt++,mxlen[u]=0;
	}
}
bool ck(){
	for(int i=1;i<=n;st[i++]=0);
	dfs1(1,0);
	dfs(1,0);
//	for(int i=1;i<=n;i++)if(st[i])cout<<i;
	
	return (cnt<=k);
}
void solve(){
	cin>>n>>k;for(int i=1;i<=n;e[i++].clear());
	for(int i=1,u,v;i<n;e[u].pb(v),e[v].pb(u),i++)cin>>u>>v;
	int l=1,r=n/2,ans;
	while(l<=r){
		mid=(l+r)/2;
		if(ck())ans=mid,r=mid-1;
		else l=mid+1;
	}cout<<ans<<"\n";
}
int main(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
	int c,T;cin>>c>>T;while(T--)solve();
	return 0;
}
