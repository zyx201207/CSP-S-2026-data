#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n, m,a[100010],b;
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(a[2]&a[1])
        {
            b=a[1];
            if(a[3]&a[2])
            {
                b=a[0];
                if(a[4]&a[3])
                {
                    b=a[3];
                }
            }
        }
    }
    cout << b;
    return 0;
}

