#include <iostream>
using namespace std;
int a[200005];
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if(n == m)
    {
        int sum = a[1];
        for(int i = 2; i <= n; i++)
        {
            sum = sum & a[i];
        }
        cout << sum;
    }
    else if(m == 1)
    {
        int maxn = -1e9;
        for(int i = 1; i <= n; i++)
        {
            maxn = max(maxn, a[i]);
        }
        cout << maxn;
    }
    else if(m == 2)
    {
        int maxn = -1e9;
        for(int i = 1; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                maxn = max(maxn, a[i] & a[j]);
            }
        }
        cout << maxn;
    }
    return 0;
}
