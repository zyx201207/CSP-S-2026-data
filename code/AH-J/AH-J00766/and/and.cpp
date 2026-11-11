//Eason Cyj001001 AH-J00766
#include "bits/stdc++.h"
#define int long long
using namespace std;
const int N = 2e5 + 10;
int ans;
int and_w(int v) {
    int o = v, sum=0;
    while(o) {
        sum += o%2;
        o/=2;
    }
    return sum;
}
struct node {
    int v;
    int u;
}a[N];
int n, m;

bool cmp(node x, node y) {
    if(x.u != y.u) {
        return x.u > y.u;
    }
    return x.v > y.v;
}
bool flat(int x) {
    while(x>1) {
        if(x%2==1) return false;
        x/=2;
    }
    return true;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);


    cin >> n >> m;
    bool flag = false;
    for(int i=1; i<=n; i++) {
        cin >> a[i].v;
        a[i].u = and_w(a[i].v);
        if(i==1) continue;
        if(a[i].v - a[i-1].v != 1) flag = true;
    }
    if(!flag && flat(n)) {
        //cout << "Yes\n";
        int ans = a[n].v;
        for(int i=n-1; i>=n-m+1; i--) ans &= a[i].v;
        cout << ans ;
        return 0;
    }
    sort(a+1, a+n+1, cmp);
    ans = a[1].v;
    for(int i=2; i<=min(m,n); i++) {
        int t = ans;
        t &= a[i].v;
        if(t == 0) {
            m++;
            continue;
        }
        ans = t;
    }
    cout << ans;
    return 0;
}
