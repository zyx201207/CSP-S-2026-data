#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=0x3f3f3f3f3f3f3f3f;
const int N=2e6+10;

int n,d,c,t;
int x[N],sum[N],use[N];

void solve() {
    cin>>n>>d;
    for(int i=1;i<=n;++i) cin>>x[i];
    if(c==11||c==12) {
        int dx=abs(x[2]-x[1]);
        if(dx*2>d) cout<<"0\n";
        else cout<<max(0ll,n-(d/dx)*2+1)<<"\n";
    }
    sum[1]=1;
    for(int i=2;i<=n;++i) {
        if(x[i]-x[i-1]<=d&&(x[i]-x[i-2]>d||i==2)&&(x[i+1]-x[i-1]>d||i==n)) sum[i]=sum[i-1]+1;
        else sum[i]=1;
    }
    int ans=0,las=0;
    for(int i=4;i<=n;++i) {
        use[i]=0;
        if(x[i]-x[i-1]<=d&&x[i]-x[i-2]<=d&&x[i]-x[i-3]>d&&x[i-1]-x[i-3]<=d&&x[i-2]-x[i-3]<=d) {
            use[i]=1;
            las=sum[i-3];
            ans+=sum[i-3];
        }
        else if(use[i-1]&&x[i]-x[i-1]<=d&&x[i]-x[i-2]>d) {
            ans+=las;
        }
        else las=0;
    }
    cout<<ans<<"\n";
}

signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>c>>t;
    while(t--) solve();
    return 0;
}
