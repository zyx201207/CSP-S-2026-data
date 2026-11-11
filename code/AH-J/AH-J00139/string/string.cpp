#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    int cnt;
    char op;
} a[200011];
int n, l, r;
ll ans;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d %c\n", &a[i].cnt, &a[i].op);
    }
    l = 1, r = n;
    while(l < r) {
        if(a[l].op == a[r].op) {
            if(a[l].cnt < a[r].cnt) {
                a[r].cnt -= a[l].cnt;
                l++;
            }else if(a[l].cnt > a[r].cnt) {
                a[l].cnt -= a[r].cnt;
                r--;
            }else {
                l++;
                r--;
            }
        }else {
            if(a[l].cnt < a[r].cnt) {
                ans += a[l].cnt;
                a[r].cnt -= a[l].cnt;
                l++;
            }else if(a[l].cnt > a[r].cnt) {
                ans += a[r].cnt;
                a[l].cnt -= a[r].cnt;
                r--;
            }else {
                ans += a[l].cnt;
                l++;
                r--;
            }
        }
    }
    printf("%lld", ans);
    return 0;
}