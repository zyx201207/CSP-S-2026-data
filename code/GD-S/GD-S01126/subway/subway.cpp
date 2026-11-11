#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5,N=505;
int c,n,m,d,q,w[M],cnt[M],ans=INT_MAX;
bool book[N];
struct herb{
	int to,time;
};
vector<herb>a[N];
void dfs(int now,int goal,int time){
	if(now==goal)ans=min(ans,time);
	for(int i=1;i<=n;i++){
		if(book[i])continue;
		bool b=0;
		for(auto nx:a[i]){
			if(nx.to==now){
				b=1;
				for(auto nex:a[i]){
					book[i]=1;
					if(nex.to==now)continue;
					dfs(nex.to,goal,time+nx.time+nex.time);
					book[i]=0;
				}
			}
			if(b)break;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		int la=0;
		while(k--){
			int aa,t;
			scanf("%lld%lld",&aa,&t);
			a[i].push_back(herb{aa,t});
		}
	}
	while(q--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		for(int i=1;i<=n;i++)book[i]=0;
		ans=INT_MAX;
		dfs(x,y,w[x]+w[y]);
		printf("%d\n",ans);
	}
    return 0;
}

