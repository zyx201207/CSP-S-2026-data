#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf (1ll<<62)
#define pii pair<int,int>
#define ll first
#define rr second
const int N=4005;
int link[N][N];
vector<int>e[N];
int d[N],n;
int Link(int s,int op){
	int rt;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)continue;
			if((!(s&(1ll<<i)))||(!(s&(1ll<<j))))continue;
			if(link[i+1][j+1]==op){
				e[i+1].push_back(j+1);
				e[j+1].push_back(i+1);
				rt=i+1;
			}
		}
	}
	return rt;
}
pii dfs(int x,int f){
	int ans=0,idx=x;
	for(auto t:e[x]){
		if(t==f)continue;
		d[t]=d[x]+1;
		pii dis=dfs(t,x);
		if(dis.rr>ans){
			ans=dis.rr;
			idx=dis.ll;
		}
	}
	return make_pair(idx,ans+1);
}
void solve(int op){
	int k;cin>>n>>k;
	for(int i=1;i<=n;i++){
		int u,v;cin>>u>>v;
		link[u][v]=link[v][u]=op;
	}
	int s=(1ll<<n),ans=inf;
	for(int i=0;i<s;i++){
		if(__builtin_popcount(i)!=k)continue;
		int rt=Link(i,op);
		int v=dfs(rt,0).first;
		d[v]=0;
		int u=dfs(v,0).first;
		ans=min(ans,d[u]);	
		for(int i=1;i<=n;i++)e[i].clear();
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;cin>>c>>t;
	for(int i=1;i<=t;i++)solve(i);
}
