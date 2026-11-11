#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 5;
struct node {int sx,sy,ex,ey; };
bool operator < (node a,node b) {return a.sx < b.sx;}
ll a[N],q[N];
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t; cin >> c >> t;
    while(t--) {
        ll n,d; cin >> n >> d;
        for(ll i = 1;i <= n;i++) cin >> a[i];
        ll j = 1;
        while(j <= n && a[j] - a[1] <= d) j++;
        q[1] = --j;
        if(q[1] == 1) {cout << 0 << "\n"; continue;}
        ll cur = q[1]-1; ll ans = 0;
        for(ll i = 1;q[1] * i <= n-1;i++) { ans += n-2 - (cur * i) + 1;}
        cout << ans << "\n";
    }
    return 0;
}

