#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1005],f[1005];
int app(int l,int r)
{
    bool h = 1;
    int sum[1000],s=1;
    for (int i=l;i<=r;i++)
    {
        sum[s]=a[i];
        for (int j=1;j<i;j++)
        {
            if (sum[j]==sum[s])
            {
                s = j;
                for (int k=j;k<=i;k++)
                {
                    sum[k]=0;
                }
                sum[s]=a[i];
            }
        }
        s++;
    }
    for (int i=1;i<=m;i++)
    {
        f[sum[i]]++;
    }
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >>m;
    for (int i=1;i<=n;i++)
    {
        f[i]=0;
        cin >> a[i];
    }
    for (int i=1;i<=n;i++)
    {
        app(i,n);
    }
    for (int i=1;i<=m;i++)
    {

        cout << f[i] << " ";
    }
    return 0;
}
