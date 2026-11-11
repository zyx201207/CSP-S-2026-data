#include<bits/stdc++.h>
using namespace std;
using i64=long long;
using u64=unsigned long long;
using u32=unsigned;
const int N=2e6+5;
int Cid,n;
i64 d,x[N];

vector<int>G[N];
int fa[N],w[N],cnt[N][2];

i64 Main(){
	cin>>n>>d;
	for(int i=1;i<=n;++i)cin>>x[i];
	for(int u=n,i=n;u>=1;--u){
		int j=i=min(i,u);
		for(;j>1&&x[u]-x[j-1]<=d;--j);
		G[u].resize(i-j);
		for(int v=j;v<i;++v){
			G[u][v-j]=v;
			fa[v]=u;
			w[v]=v-j;
		}
		i=j;
	}
	i64 ans=0;
	for(int u=1;u<=n;++u){
		if(!fa[u])continue;
		if(w[u]==0){
			for(int v:G[u]){
				cnt[u][0]+=cnt[v][0];
				cnt[u][1]+=cnt[v][1];
			}
		}else if(w[u]==1){
			cnt[u][1]=G[u].size();
			if(G[G[fa[u]][0]].empty()){
				for(int v:G[u]){
					cnt[u][1]+=cnt[v][0]-1;
				}
			}
		}
		++cnt[u][0];
		for(int v:G[u]){
			ans+=1ll*cnt[v][1]*(fa[u]-fa[u-1]);
			if(v+1<u){
				i64 res=cnt[v][0];
				if(G[u-1].size())res=1;
				ans+=1ll*res*(fa[u-1]-fa[u-2]);
			}
		}
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	for(cin>>Cid>>t;t--;){
		cout<<Main()<<'\n';
		for(int i=1;i<=n;++i){
			G[i].clear();
			fa[i]=w[i]=cnt[i][0]=cnt[i][1]=0;
		}
	}
}