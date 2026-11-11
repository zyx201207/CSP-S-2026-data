#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,x = 1,a[500005],b[300005];
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = x;i <= n;i++)
    {
        for(int j = i;j >= x;j--)
        {
            if(a[i] == a[j])
            {
                a[i + j - 1] = a[i];
            }
        }
    }
    for(int i = 1;i <= m;i++)
    {
        b[a[i]] += 1;
    }
    for(int i = 1;i <= m;i++)
    {
        cout << b[i] << ' ';
    }
    return 0;
}
