#include <bits/stdc++.h>
using namespace std;
long long n,L,m,ans;

struct Node{
    long long num;
    char c;
}a[200010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> a[i].num >> a[i].c;
        L+=m;
    }
    long long l=1,r=n;
    while (l <= r) {
        if (a[l].c == a[r].c) {
            if (a[l].num == a[r].num) {
                a[l].num=0;
                a[r].num=0;
                l++;
                r--;
            } else if (a[l].num > a[r].num) {
                a[l].num-=a[r].num;
                a[r].num=0;
                r--;
            } else {
                a[r].num-=a[l].num;
                a[l].num=0;
                l++;
            }
        } else {
            if (a[l].num == a[r].num) {
                ans+=a[l].num;
                a[l].num=0;
                a[r].num=0;
                l++;
                r--;
            } else if (a[l].num > a[r].num) {
                ans+=a[r].num;
                a[l].num-=a[r].num;
                a[r].num=0;
                r--;
            } else {
                ans+=a[l].num;
                a[r].num-=a[l].num;
                a[l].num=0;
                l++;
            }
        }
    }
    cout << ans;
    return 0;
}
