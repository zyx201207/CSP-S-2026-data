#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
const int N=2e6+5;
int n,nxt[N],lf[N],cnt[N],rp[N]; ll d,x[N],ans,sum[N],f[N];
void solve() {
    ans=0;
    cin>>n>>d;
    rep(i,1,n) cin>>x[i];
    rep(i,1,n) lf[i]=i;
    rep(i,1,n) {
        int l=i+1,r=n,nx=i;
        while(l<=r) {
            int mid=l+r>>1;
            if(x[mid]-x[i]<=d) nx=mid,l=mid+1;
            else r=mid-1;
        }
        nxt[i]=nx;
        lf[nxt[i]]=min(lf[nxt[i]],i);
    }
    per(i,n-1,1) lf[i]=min(lf[i],lf[i+1]);
    rep(i,1,n-1) {
        int r=i,nc=0;
        while(r<n) {
            int rr=nxt[r];
            ++nc;
            rp[nc]=rr;
            rep(j,r+1,rr) cnt[j]=nc;
            if(r==rr) { r=rr; break; }
            r=rr;
        }
        f[i]=1;
        rep(j,nxt[i-1]+1,nxt[i]) f[j]=1,sum[j]=sum[j-1]+f[j];
        rep(j,nxt[i]+1,r) {
            f[j]=sum[rp[cnt[j]-1]]-sum[lf[j]-1];
            if(f[j]==2) { /*cerr<<i<<' '<<j<<'\n';*/ ++ans;}
            sum[j]=sum[j-1]+f[j];
        }
    }
    cout<<ans<<'\n';
}
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int c,t; cin>>c>>t;
    while(t--)
    solve();
    //cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n';
    return 0;
}

