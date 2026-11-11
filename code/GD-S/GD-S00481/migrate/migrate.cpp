#include <bits/stdc++.h>
#define ll long long
#define pil pair<int,ll>
#define fi first
#define sc second
#define pb push_back
using namespace std;

int c,t,n;
ll d,s[2000007],ans,cnt,tmp[2000007];
vector<pil>g[2000007];

void dfs(int u,int e,int w){
	if(u==e){
		tmp[w]++;
		return;
	}
	for(pil p:g[u]){
		int v=p.fi;
		ll w=p.sc;
		if(w<=d){
			dfs(v,e,w+1);
		}
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>s[i];
			g[i].clear();
		}
		for(int i=1;i<=n-1;++i){
			for(int j=i+1;j<=n;++j){
				g[i].pb({j,s[j]-s[i]});
			}
		}
		for(int i=1;i<=n-1;++i){
			for(int j=i+1;j<=n;++j){
				cnt=0;
				for(int k=1;k<=n;++k)tmp[k]=0;
				if(s[j]-s[i]<=d)continue;
				dfs(i,j,0);
				for(int k=1;k<=n;++k){
					if(tmp[k]){
						if(tmp[k]==2)ans++;
						else break;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
