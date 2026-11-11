#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5*100+10,M=5e5+10;
int c,n,m,D,q,d[M],w[M];
vector<pair<int,int>>e[N];
ll dp[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&D,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	int mxd=0;
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		int lst=0;
		for(int j=1;j<=k;j++){
			int a,t;
			scanf("%d%d",&a,&t);
			d[a]++;
			mxd=max(mxd,d[a]);
			e[d[a]*m+a].push_back({(d[a]+21)*m+a,w[a]});
			e[(d[a]+21)*m+a].push_back({d[a]*m+a,w[a]});
			e[(d[a]+21)*m+a].push_back({(d[a]+41)*m+a,t});
			e[(d[a]+41)*m+a].push_back({(d[a]+21)*m+a,t});
			if(!lst)lst=a;
			else{
				e[(d[a]+41)*m+a].push_back({(d[lst]+41)*m+lst,0});
				e[(d[lst]+41)*m+lst].push_back({(d[a]+41)*m+a,0});
				lst=a;
			}
		}
	}
	for(;q--;){
		int s,t;
		scanf("%d%d",&s,&t);
		set<pair<ll,int>>st;
		for(int i=1;i<=100*m;i++)dp[i]=1ll<<60;
		for(int i=1;i<=d[s];i++)
			dp[i*m+s]=0;
		for(int i=1;i<=100*m;i++)
			st.insert({dp[i],i});
		while(!st.empty()){
			int u=st.begin()->second;
			st.erase(st.begin());
			for(auto x:e[u]){
				int v=x.first,w=x.second;
					if(dp[v]>dp[u]+w){
						st.erase({dp[v],v});
						dp[v]=dp[u]+w;
						st.insert({dp[v],v});
					}	
				
			}
		}
		ll ans=1ll<<60;
		for(int i=1;i<=d[t];i++)ans=min(ans,dp[i*m+t]);
		printf("%lld\n",ans);
	}
}
