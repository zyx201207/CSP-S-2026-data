#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m,ans;

int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
    }
    sort (a+1,a+n+1);
    ans = a[n];
    for (int i=n;i>(n-m);i--) {
        ans &= a[i];
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
