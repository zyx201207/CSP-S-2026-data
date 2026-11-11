#include <bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int c[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for (int i=1;i<=n;i++)
    {
        memset(c,0,sizeof(c));
        int l=0;
        for (int j=i;j<=n;j++)
        {
            l++;
            c[l]=a[j];
            for (int k=1;k<l;k++)
            {
                if (c[k]==c[l])
                {
                    l=k;
                    break;
                }
            }
        }
        for (int j=1;j<=l;j++)
        {
            b[c[j]]++;
        }
    }
    for (int i=1;i<=m;i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}
