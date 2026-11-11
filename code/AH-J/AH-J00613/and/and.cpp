#include <bits/stdc++.h>
using namespace std;
int n,m,maxn = 0;
int a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= m;i++)
    {
        for(int j = i + 1;j <= n;j++)
        {
            maxn = max(maxn,a[i] & a[j]);
        }
    }
    cout << maxn;
    return 0;
}
