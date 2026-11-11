#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n, m;
    int x[1000];
    cin >> n >> m;
    int a[100];
    int y[100];

    for(int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }

    for(int i = 1; i <= m; i++)
    {
        a[i] = i;
        if(a[i] == x[n-1])
        {
            y[i] = n;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n-i; j++)
        {
            if(x[i] == x[i+j])
            {
                continue;
            }
            else
            {
                y[i]++;
            }
        }
    }

    for(int i = 1; i <= m; i++)
    {
        cout << y[i] << " ";
    }
    return 0;
}
