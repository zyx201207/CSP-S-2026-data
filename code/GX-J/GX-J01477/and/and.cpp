#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n, m, a[1000];
    int x = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i] and a[i+1])
            {
                x = a[i];
            }
        }
    }
    cout << x;

    return 0;
}
