#include <bits/stdc++.h>
using namespace std;
int n,m,a[50000005],x;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for (int i = 1;i <= n * n;i++)
    {
        for (int j = 1;j < n;j++)
        {
            if (a[i] < a[i + 1])
            {
                x = a[i + 1];
                a[i+1] = a[i];
                a[i] = x;
            }
        }
    }
    cout << a[2];
    return 0;
}
