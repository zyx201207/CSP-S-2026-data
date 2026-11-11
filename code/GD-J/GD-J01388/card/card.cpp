#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+5;
int n,m,ans,a[maxn],cnt[maxn];
namespace hyw {
    int pos[maxn];
    bool check() {
        return n==m;
    }
    void solve() {
        for (int i=1;i<=n;i++)
            pos[a[i]]=i;
        for (int i=1;i<=n;i++)
            cout<<pos[i]<<" ";
    }
}
namespace small {
    int lst[maxn],pos[maxn];
    bool ok[maxn];
    bool check() {
        return n<=5000;
    }
    void solve() {
        for (int i=1;i<=n;i++) {
            if (pos[a[i]]!=0) lst[pos[a[i]]]=i;
            pos[a[i]]=i;
        }
        for (int i=1;i<=n;i++) {
            fill(ok+1+i,ok+1+n,false);
            // int pos=0;
            // cout<<i<<"\n";
            for (int j=i;j<=n;) {
                ok[j]=true;
                if (lst[j]!=0) ok[j]=false,j=lst[j];
                else j++;
            }
            for (int j=i;j<=n;j++)
                if (ok[j]) cnt[a[j]]++;
            // for (int i=1;i<=m;i++)
            //     cout<<cnt[i]<<" ";
            // cout<<'\n';
        }
        for (int i=1;i<=m;i++)
            cout<<cnt[i]<<" ";
    }
}
namespace suba {
    bool check() {
        for (int i=1;i<n;i++)
            if (a[i]>a[i+1]) return false;
        return true;
    }
    void solve() {
        for (int i=1;i<=n;i++)
            if (a[i]!=a[i+1]) cout<<i<<" ";
    }
}
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    if (hyw::check()) {
        hyw::solve();
        return 0;
    }
    if (suba::check()) {
        suba::solve();
        return 0;
    }
    small::solve();
    return 0;
}