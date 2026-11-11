#include<stdio.h>
#include<algorithm>
#include<vector>
typedef long long ll;
const int N=5e5+5,M=505;
struct node{
	int to;
	ll val;
	node(int _to=0,ll _val=0):to(_to),val(_val){}
};
std::vector<node> v[N],p[N];
int C,n,m,d,q;
ll w[N],dp[M][M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&C,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int T=1,siz,x;T<=n;T++){
		ll y;
		scanf("%d",&siz);
		while(siz--) scanf("%d%lld",&x,&y),v[x].emplace_back(T,y),p[T].emplace_back(x,y);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dp[i][j]=1e18;
		dp[i][i]=0;
	}
	for(int i=1;i<=n;i++) for(auto j:p[i]) for(auto k:v[j.to]) dp[i][k.to]=std::min(dp[i][k.to],j.val+k.val);
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=std::min(dp[i][j],dp[i][k]+dp[k][j]);
	int x,y;
	while(q--){
		scanf("%d%d",&x,&y);
		ll ans=1e18;
		for(auto i:v[x]) for(auto j:v[y]) ans=std::min(ans,w[x]+w[y]+i.val+j.val+dp[i.to][j.to]);
		printf("%lld\n",ans);
	} 
	return 0;
}
