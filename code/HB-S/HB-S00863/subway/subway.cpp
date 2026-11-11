#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el "\n"

int c,n,m,d,q,ans,w[500005],k[500005];
signed main()
{
    freopen("subway","r",stdin);
    freopen("subway","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i)cin>>w[i];
    for(int i=1;i<=m;++i){
        ans+=w[i];
    }
    cout<<ans<<el<<ans/2+1;
    return 0;
}
