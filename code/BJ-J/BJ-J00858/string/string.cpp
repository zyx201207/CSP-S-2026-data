#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
struct node {
    char c;
    ll st;
    ll ed;
    ll len;
}a[N];
int n;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    ll id = 1;
    for(int i = 1; i <= n; i ++ ) {
        char ch;
        int x;
        cin >> x >> ch;
        a[i].c = ch;
        a[i].st = id;
        id += x;
        a[i].ed = id - 1;
        a[i].len = a[i].ed - a[i].st + 1;
    }
    ll l = 1, r = a[n].ed, idl = 1, idr = n, cnt = 0;
    while(l <= r) {
        int lel = a[idl].len, ril = a[idr].len;
        if(a[idl].c != a[idr].c) cnt += (max(lel, ril) - abs(lel - ril));
        if(lel < ril) {
            l += lel;
            r -= lel;
            idl ++ ;
            a[idr].len -= lel;
        }
        else if(lel > ril) {
            l += ril;
            r -= ril;
            idr -- ;
            a[idl].len -= ril;
        }
        else {
            l += lel;
            r -= ril;
            idl ++ ;
            idr -- ;
        }
        if(idl == idr) break;
    }
    cout << cnt;
    return 0;
}
