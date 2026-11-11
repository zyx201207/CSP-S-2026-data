#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
int c,n,k,d[N],fa[N];
vector<int>e[N];
int fd(int x){return ((fa[x]==x)?x:fa[x]=fd(fa[x]));}

int calc(int S){
	if(__builtin_popcount(S)>k)return 0x3f3f3f3f;
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=n;++i)
		if((S>>(i-1))&1)
			for(int j:e[i])
				if((S>>(j-1))&1){
					int u=fd(i),v=fd(j);
					if(u!=v)fa[u]=v;
				}
	set<int>s;
	for(int i=1;i<=n;++i)if((S>>(i-1))&1)s.insert(fd(i));
	if(s.size()>2)return 0x3f3f3f3f;
	queue<int>q;
	for(int i=1;i<=n;++i)d[i]=0x3f3f3f3f;
	for(int i=0;i<n;++i)if((S>>i)&1)q.push(i+1),d[i]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:e[u])if(d[v]>d[u]+1){d[v]=d[u]+1;q.push(v);}
	}
	int ret=0;
	for(int i=1;i<=n;++i)ret=max(ret,d[i]);
	if(S==322)cerr<<ret<<endl;
	return ret;
}

void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;++i)e[i].clear();
	for(int i=1;i<=n-1;++i){
		int u,v;cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int ans=0x3f3f3f3f;
	for(int i=0;i<(1<<n);++i)
		ans=min(ans,calc(i));
	cout<<ans<<"\n";
	return ;
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;cin>>c>>T;while(T--)solve();
	return 0;
}
