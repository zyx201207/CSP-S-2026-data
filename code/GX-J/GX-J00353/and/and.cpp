#include <bits/stdc++.h>
using namespace std;

int a[200005], b[200005];
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m, sum = 0;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    if(m == n)
    {
        for(int i = 1;i <= n;i++)
        {
            sum += a[i] & a[i + 1];
        }
        cout << sum;
    }
    if(m == 2)
    {
        int q = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                q++;
                b[q] = a[i] & a[j];
            }
        }
        sort(b + 1, b + q + 1);
        cout << b[q];
    }
}
