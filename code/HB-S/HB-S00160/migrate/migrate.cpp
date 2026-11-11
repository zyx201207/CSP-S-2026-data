#include <bits/stdc++.h>
#define rep(i,j,n) for (int i=j;i<=n;++i)
#define rrep(i,j,n) for (int i=n;i>=j;--i)
#define file(name) \
freopen(#name".in","r",stdin); \
freopen(#name".out","w",stdout);
using namespace std;
typedef long long ll;
constexpr int N = 2e6+50;
int R[N],n;
ll x[N],d;
int stk[N],top;
int main() {
    cin.tie(0),cout.tie(0);ios::sync_with_stdio(0);
    file(migrate)
    int c,T;cin >> c >> T;
    while (T--) {
        cin >> n >> d;
        rep(i,1,n) cin >> x[i];
        int j = 1;
        ll res=0;
        rep(i,1,n) {
            for (;j<n&&x[j+1]-x[i]<=d;j++);
            R[i] = j;
        }
        if (n<=5000) {
            rep(i,1,n) {
                if (R[i]==n) break;
                top=0;
                rep(j,i+1,R[i]) stk[++top] = j;
                int k=1;
                rep(j,R[i]+1,n) {
                    for (;k<top&&x[j]-x[stk[k]]>d;k++);
                    int cnt = top-k+1;
                    if (cnt<=1)  stk[++top] = j;
                    else if (cnt==2) res++;
                }
            }
        }
        cout << res << '\n';
    }

    cerr << (double)clock()/CLOCKS_PER_SEC;

    return 0;
}