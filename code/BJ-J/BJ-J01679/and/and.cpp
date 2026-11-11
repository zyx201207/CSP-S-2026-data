#include <bits/stdc++.h>
using namespace std;

int n,m,a[100005];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    int x = a[1] & a[2];
    for(int i = 3;i <= n;i++) x = x & a[i];
    cout << x << endl;
    return 0;
}
