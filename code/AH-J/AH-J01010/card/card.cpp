#include<bits/stdc++.h>
using namespace std;
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,a[500005],b[500005],c[300003];
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= m;i++)
    {
        c[i]=0;
    }
    for(int i = 1;i <= n;i++)
    {
        int h=0;
        for(int j=i;j <= n;j++)
        {
            h++;
            for(int k = i;k <= j;k++)
            {
                if(a[k]==a[j]&&h!=1)
                {
                    h=k;
                }
            }
            b[h]=a[j];
        }
        for(int j = 1;j <= h;j++)
        {
            c[b[h]]++;
        }
    }
    for(int i = 1;i <= m;i++)
    {
        cout << c[i] << " ";
    }
    return 0;
}
