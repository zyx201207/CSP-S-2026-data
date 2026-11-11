#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005],r=1;
void runn(int l) {
    cnt[a[l]]++;
    for (int i = n;i >= l;--i) {
        if (a[i] == a[l]) {
            runn(i+1);
            return;
        }
    }
    if(l<n)runn(l+1);
    else return;
}
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;++i) {
        cin >> a[i];
    }
    for (int i = 1;i <= n;++i) {
        runn(i);
    }
    for (int i = 1;i <= m;++i) {
        cout << cnt[i] << ' ';
    }
    return 0;
}
