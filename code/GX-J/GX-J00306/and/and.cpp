#include <bits/stdc++.h>
using namespace std;

int n, m, a[200005], maxn=-1;

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];

    for(int i=1; i<=n-m+1; i++)
    {
        int su=a[i], dx=0;
        while(m+i-1+dx<=n)
        {
            for(int j=i+1+dx; j<=m+i-1+dx; j++)
            {
                su=su&a[j];
            }
            maxn=max(maxn, su);
            dx++;
            su=a[i];
        }
    }

    cout << maxn;

    return 0;
}
