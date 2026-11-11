#include <bits/stdc++.h>
using namespace std;
struct node{
    int len;
    char ch;
}a[200005];
int n;
long long ans;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].len >> a[i].ch;
    }
    int l=1, r=n;
    while(l <= r) {
        char t1=a[l].ch, t2=a[r].ch;
        int s1=a[l].len, s2=a[r].len;
        if(t1 != t2) ans += min(s1, s2);
        if(s1 < s2) {
            l++;
            a[r].len -= s1;
        }
        else if(s1 == s2) {
            l++;
            r--;
        }
        else {
            r--;
            a[l].len -= s2;
        }
    }
    cout << ans << endl;
    return 0;
}