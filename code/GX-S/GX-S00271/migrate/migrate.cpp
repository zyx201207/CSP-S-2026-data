#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,d,x[301],in[301],f[301],dis[301],ans;
vector<int> ve[301];
void sl(int st){
	memset(f,0,sizeof(f));memset(dis,0x3f,sizeof(dis));
	f[st]=1;dis[st]=0;
	for(int i=st;i<=n;++i){
		for(int j:ve[i]) ++in[j];
	}
	queue<int> q;
	q.push(st);
	while(!q.empty()){
		int fr=q.front();q.pop();
		for(int v:ve[fr]){
			--in[v];
			if(dis[fr]+1==dis[v]) f[v]+=f[fr];
			else if(dis[fr]+1<dis[v]) f[v]=f[fr],dis[v]=dis[fr]+1;
			if(f[v]>2) f[v]=3;
			if(!in[v]) q.push(v);
		}
	}
	for(int i=1;i<=n;++i) ans+=(f[i]==2);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>x[i],ve[i].clear();
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j) if(x[j]-x[i]<=d) ve[i].push_back(j);
		}
		for(int i=1;i<=n;++i) sl(i);
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}
