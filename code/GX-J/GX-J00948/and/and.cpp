#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200005],c;
    int b = -1;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    if(m == 1)
    {
        for(int i = 1;i <= n;i++)
        {
            c = a[i];
            if(a[i + 1] > c)
            {
                c = a[i + 1];
            }
        }
        cout << c;
    }
    if(m == 2)
    {
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                if(a[i] & a[j] > b)
                {
                    b = a[i] * a[j];
                }
            }
        }
        cout << b;
    }


    return 0;
}
