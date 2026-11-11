#include <bits/stdc++.h>
using namespace std;

int a[500005];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    if(m == 1)
    {
        cout << n;
        return 0;
    }
    if(m == 2)
    {
        if(a[n] == 1)
        {
            for(int i = n;i >= 1;i--)
            {
                if(a[i] == 2)
                {
                    cout << n << ' ' << i;
                    return 0;
                }
            }
        }
        if(a[n] == 2)
        {
            for(int i = n;i >= 1;i--)
            {
                if(a[i] == 1)
                {
                    cout << i << ' ' << n;
                    return 0;
                }
            }
        }
    }
    return 0;
}
