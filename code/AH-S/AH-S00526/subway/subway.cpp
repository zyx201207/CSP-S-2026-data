#include<bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i=(a);i<=(b);++i)
#define rp(i,a,b) for(int i=(a);i>=(b);--i)
#define int long long
#define fi first
#define se second
const int N=5e5+5;
int n,m,cid,d,q,w[N],f[505][505];vector<pair<int,int> >p[N];
signed main() {
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  scanf("%lld%lld%lld%lld%lld",&cid,&n,&m,&d,&q);
  fr(i,1,m) scanf("%lld",w+i);
  fr(i,1,n) {
    int k,a,t;scanf("%lld",&k);
    fr(j,1,k) scanf("%lld%lld",&a,&t),p[a].push_back({i,t});
  }
  fr(i,1,n) fr(j,1,n) f[i][j]=1e18;
  fr(i,1,n) f[i][i]=0;
  fr(i,1,m) for(pair<int,int>x:p[i]) for(pair<int,int>y:p[i]) if(x.fi!=y.fi) f[x.fi][y.fi]=min(f[x.fi][y.fi],x.se+y.se);
  fr(k,1,n) fr(i,1,n) fr(j,1,n) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
  fr(i,1,q) {
    int x,y,ans=1e18;scanf("%lld%lld",&x,&y);
    for(pair<int,int>a:p[x]) for(pair<int,int>b:p[y]) ans=min(ans,a.se+b.se+f[a.fi][b.fi]);
    printf("%lld\n",ans+w[x]+w[y]);
  }
	return 0;
}