#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int> 
#define dle long double
#define fi first
#define sec second
#define rep(i,a,b) for(int i = (a);i<=(b);i++)
#define per(i,a,b) for(int i = (a);i>=(b);i--)
#define endl '\n'
const int MAXN = 2e5+10;
int n,m,a[MAXN],vis[MAXN],res[50];
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;rep(i,1,n) cin>>a[i],
    vis[i] = 1;per(i,31,0) { 
        int cnt = 0;rep(j,1,n) 
            if(vis[j]&&(a[j]>>i&1))
                cnt++;
        // cout<<i<<' '<<cnt<<endl;
        // rep(i,1,n) cout<<vis[i]<<' ';cout<<endl;
        if(cnt>=m) { 
            res[i] = 1;rep(j,1,n) 
                if(vis[j]&&!(a[j]>>i&1))
                    vis[j] = 0;
        }
    }int ans = 0,tmp = 1;rep(i,0,31) 
        ans += res[i]*tmp,tmp *= 2;
    cout<<ans<<endl;
    return 0;
}