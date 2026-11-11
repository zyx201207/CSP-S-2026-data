#include <bits/stdc++.h>
using namespace std;
int a[100005];
int maxn = INT_MIN;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i<=n;i++)
    {
        maxn = max(maxn,a[j]);
    }
    cout << maxn;
    return 0;
}
