#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

typedef long long ll;

const int MAXN=5e2+5;
const int MAXM=5e5+5;

int c,n,m,d,q,len[MAXN];

ll w[MAXM],dis[MAXN][MAXN];

struct Road{
	int ed;
	ll val;
};

vector <Road> G[MAXN],sub[MAXM];

inline bool cmp(Road ra,Road rb){
	return ra.ed<rb.ed;
}

inline void prework(){
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) dis[i][j]=inf;
		dis[i][i]=0;
	} 
	for (int i=1;i<=n;i++){
		scanf("%d",&len[i]);
		for (int j=1;j<=len[i];j++){
			int ed;
			ll val;
			scanf("%d%lld",&ed,&val);
			G[i].push_back({ed,val}),sub[ed].push_back({i,val});
		}
		stable_sort(G[i].begin(),G[i].end(),cmp);
	}
	for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++){
		int pa=0,pb=0;
		while (pa<len[i]&&pb<len[j]){
			while (pa<len[i]&&G[i][pa].ed<G[j][pb].ed) pa++;
			while (pb<len[j]&&G[i][pa].ed>G[j][pb].ed) pb++;
			if (pa<len[i]&&pb<len[j]&&G[i][pa].ed==G[j][pb].ed){
				ll res=G[i][pa].val+G[j][pb].val;
				dis[i][j]=min(dis[i][j],res),dis[j][i]=min(dis[j][i],res);
				pa++,pb++;
			}
		}
	}
	return;
}

inline void solve(){
	for (int mid=1;mid<=n;mid++) for (int l=1;l<=n;l++) for (int r=1;r<=n;r++){
		if (dis[l][mid]>=inf||dis[mid][r]>=inf) continue;
		dis[l][r]=min(dis[l][r],dis[l][mid]+dis[mid][r]);
	}
	for (int i=1,x,y;i<=q;i++){
		scanf("%d%d",&x,&y);
		ll ans=inf;
		for (int i=0;i<(int)sub[x].size();i++) for (int j=0;j<(int)sub[y].size();j++){
			ans=min(ans,sub[x][i].val+dis[sub[x][i].ed][sub[y][j].ed]+sub[y][j].val);
		}
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
	return;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	prework();
	solve();
	return 0;
}
