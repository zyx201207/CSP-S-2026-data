//Eason Cyj001001 AH-J00766
#include "bits/stdc++.h"
#define int long long

using namespace std;
const int N = 2e5 + 10;
struct node{
    char c;
    int p;
}a[N];
int n;
int ans;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);


    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i].p >> a[i].c;
    }
    int l=1, r=n;
    while(l<r) {
        int q = min(a[r].p, a[l].p);
        if(a[l].c != a[r].c) {
            ans += q;
        }
        a[l].p -= q; a[r].p -= q;
        //cout << l << " " << r << " " << a[l].p << " " << a[r].p << " " << ans << endl;
        if(a[l].p == 0) l++;
        if(a[r].p == 0) r--;
    }
    cout << ans;
    return 0;
}
