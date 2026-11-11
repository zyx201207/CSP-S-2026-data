#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], ans;
bool cmp(int a, int b) {return a>b;}
int main()
{
    freopen("string.in", "w", "in");
    freopen("string.out", "r", "out");
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> a[i], a[i]=a[i]^m;
    sort(a+1,a+n+1,cmp);
    for (int i=1; i<=m; i++) ans+=a[i];
    cout << ans;
}