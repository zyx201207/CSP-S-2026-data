#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int> 
#define dle long double
#define fi first
#define sec second
#define rep(i,a,b) for(int i = (a);i<=(b);i++)
#define rep(i,a,b) for(int i = (a);i<=(b);i++)
#define endl '\n'
const int MAXN = 5e5+10;
int n,m,a[MAXN],ans[MAXN],pre[MAXN],sz,b[MAXN];
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;rep(i,1,n) cin>>a[i];
    rep(i,1,n) { rep(j,1,m) pre[j] = 1e18;
        sz = 0;rep(j,i,n) if(pre[a[j]]!=1e18) {
            rep(k,pre[a[j]]+1,sz) if(pre[b[k]]==k)
                pre[b[k]] = 1e18;sz = pre[a[j]];
        } else b[++sz] = a[j],pre[a[j]] = sz;
        rep(j,1,sz) ans[b[j]]++;
    }rep(i,1,m) cout<<ans[i]<<' ';
    return 0;
}