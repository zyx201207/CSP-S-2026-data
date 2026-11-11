#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node {
    char ch;
    ll len;
} a[200005];

int n;
ll ans,tot,L,R,l,r;

int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].len >> a[i].ch;
        tot = tot + a[i].len;
    }
    if (tot % 2 == 0) {
        L = (tot / 2),R = (tot / 2) + 1;
    }
    else {
        L = (tot + 1) / 2 - 1,R = (tot + 1) / 2 + 1;
    }
    l = 1LL,r = tot;
    int nowl = 1,nowr = n,lstl = 0,lstr = 0;
    while (l <= L && r >= R) {
        int lenl = a[nowl].len - lstl,lenr = a[nowr].len - lstr;
        if (lenl < lenr) {
            int flag = 1;
            if (a[nowl].ch == a[nowr].ch) flag = 0;
            ans = (ll) ans + flag * lenl;
            nowl++,lstl = 0;
            lstr += lenl;
            l += lenl,r -= lenl;
        }
        else if (lenl > lenr) {
            int flag = 1;
            if (a[nowl].ch == a[nowr].ch) flag = 0;
            ans = (ll) ans + flag * lenr;
            nowr--,lstr = 0;
            lstl += lenr;
            l += lenr,r -= lenr;
        }
        else {
            int flag = 1;
            if (a[nowl].ch == a[nowr].ch) flag = 0;
            ans = (ll) ans + flag * lenl;
            nowl++,lstl = 0;
            nowr--,lstr = 0;
            l += lenl,r -= lenl;
        }
    }
    cout << ans;
    return 0;
}
