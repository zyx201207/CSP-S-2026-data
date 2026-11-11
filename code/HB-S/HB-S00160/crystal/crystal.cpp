#include <bits/stdc++.h>
#define rep(i,j,n) for (int i=j;i<=n;++i)
#define rrep(i,j,n) for (int i=n;i>=j;--i)
#define file(name) \
freopen(#name".in","r",stdin); \
freopen(#name".out","w",stdout);
using namespace std;
typedef long long ll;
constexpr int N = 5e5+50;
ll n,m;
ll a[N],s[N];

int main() {
    cin.tie(0),cout.tie(0);ios::sync_with_stdio(0);
    file(crystal)
    cin >> n >> m;
    rep(i,1,n) cin >> a[i];
    sort(a+1,a+1+n);
    rep(i,1,n) s[i] = s[i-1]+a[i];
    ll ans=1,res=0;
    rep(i,1,n) {
        ll start = ans*a[i];
        ll tmp = s[i-ans+1];
        while (ans<=i&&s[i]-s[i-ans]+m>=ans*a[i]) {
            ans++;
        }
        if (ans==i+1) ans = i;
        if (s[i]-s[i-ans]+m<ans*a[i]) ans--;
        res = max(res,ans);
    } 
    cout << res << '\n';

    // cerr << (double)clock()/CLOCKS_PER_SEC;

    return 0;
}