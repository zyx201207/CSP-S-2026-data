#include <bits/stdc++.h>
using namespace std;

const int N=2e5+6,K=30;
int n,m,a[N],ans;
bitset<N> vis[K];

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int k=29;k>=0;k--) {
        for (int i=1;i<=n;i++) if ((a[i]>>k)&1) vis[k][i]=1;
        if (k!=29) vis[k]&=vis[k+1];
        if (vis[k].count()>=m)
            ans|=(1<<k);
        else if (k!=29) vis[k]=vis[k+1];
        else for (int i=1;i<=n;i++) vis[k][i]=1;
    }
    cout<<ans;
    return 0;
}
