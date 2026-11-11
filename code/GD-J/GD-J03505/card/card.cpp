#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(x,a,b,c) for(int x=a;b;x+=c)
#define rep2(x,a,b,c) for(int x=a;b;x-=c)
#define fop(x) freopen(x".in","r",stdin); freopen(x".out","w",stdout);
const int INF=INT_MAX/3,N=5e5+20;
ll a[N],n,m,ans[N];
int main() {
	fop("card");
	scanf("%lld%lld",&n,&m);
	rep(i,1,i<=n,1) scanf("%lld",&a[i]);
	rep(i,1,i<=n,1) {
		vector<pair<int,int> > vis(m+20);
		vector<int> now(n+20,0);
		int cnt=0;
		rep(j,i,j<=n,1) {
			if(vis[a[j]].first) cnt=vis[a[j]].second-1;
			now[++cnt]=a[j],vis[a[j]].first=1,vis[a[j]].second=j;
		}
		rep(j,1,j<=m,1) ans[j]+=vis[j].first;
	}
	rep(i,1,i<=m,1) printf("%lld ",ans[i]);
	return 0;
}
