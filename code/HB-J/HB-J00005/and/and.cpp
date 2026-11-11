#include <bits/stdc++.h>
using namespace std;

int a[200005];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    if(m == 1)
    {
        int maxn = a[1];
        for(int i = 2;i <= n;i++)
        {
            if(a[i] > maxn)
                maxn = a[i];
        }
        cout << maxn;
        return 0;
    }
    if(m == n)
    {
        int sum = a[1];
        for(int i = 2;i <= n;i++)
        {
            sum &= a[i];
        }
        cout << sum;
        return 0;
    }
    if(m == 2)
    {
        int maxx = -1;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i+1;j <= n;j++)
            {
                if(a[i] & a[j] > maxx)
                    maxx = a[i] & a[j];
            }
        }
        cout << maxx;
    }
    return 0;
}
