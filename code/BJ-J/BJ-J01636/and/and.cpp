#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[2000005];
int cnt;

int main() {

    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    sort (a+1, a+n+1);
    cnt=a[n];
    for (int i=n-1; i>=n-m+1; i--) {
        cnt=cnt||a[i];
    }
    cout << cnt;

    return 0;
}