#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define f first
#define s second
#define lowbit(op) (op&-op)
inline pii operator + (const pii &x,const pii &y) {return {x.f+y.f,x.s+y.s};}
inline pii operator - (const pii &x,const pii &y) {return {x.f-y.f,x.s-y.s};}
inline int operator ^ (const pii &x,const pii &y) {return x.f*y.s-x.s*y.f;}

const int maxn=500010;
int n;
ll m;
ll a[maxn];

inline bool check(int k) {
    ll cnt=0;
    for (int i = 1; i <= k; i++) cnt+=a[i];
    for (int i = 1; i+k-1 <= n; i++) {
        if(a[i+k-1]*k-cnt<=m) return true;
        cnt+=a[i+k]-a[i];
    }
    return false;
}

signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    int l=1,r=n+1;
    while(l<r) {
        int mid=l+r>>1;
        if(check(mid)) l=mid+1;
        else r=mid;
    }
    cout << l-1 << '\n';
    return 0;
}