#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN=500;
const int MAXM=5e5;

ll c,m,n,d,q; //m ditiezhan n xianlu
ll w[MAXM+5];

vector<pair<int,ll>>to[MAXN+5];    //luxian->zhandian
vector<pair<int,ll>>sub[MAXM+5];   //zhandian->luxian
ll g[MAXN+5][MAXN+5];

//80pts

int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++) {
		int kkk;
		scanf("%d",&kkk);
		for(int j=1;j<=kkk;j++) {
			ll a,kk;
			scanf("%lld%lld",&a,&kk);
			sub[a].emplace_back(make_pair(i,kk));
			to[i].emplace_back(make_pair(a,kk));
		}
	}
	memset(g,0x3f,sizeof(g));
	for(int i=1;i<=n;i++) {
		g[i][i]=0ll;
		for(auto now:to[i]) {
			if(sub[now.first].size()==0) continue;
			for(auto nxt:sub[now.first]) {
				g[i][nxt.first]=min(g[i][nxt.first],now.second+nxt.second);
			}
		}
	}
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	while(q--) {
		int l,r;
		scanf("%d%d",&l,&r);
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(auto u:sub[l]) {
			for(auto v:sub[r]) {
				int st=u.first,ed=v.first;
				ans=min(ans,g[st][ed]+u.second+v.second);
			}
		}
		printf("%lld\n",ans+w[l]+w[r]);
	} 
    return 0;
}
