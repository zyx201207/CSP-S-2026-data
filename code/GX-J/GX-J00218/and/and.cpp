#include <bits/stdc++.h>
using namespace std;
int a[202000],n,m,sum;
int main()
{
    freopen ("and,in","r",stdin);
    freopen ("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if (m==1)
    {
        sum=a[1];
        for (int i=1;i<=n;i++)
        {
            if (a[i]>sum)
            {
                sum=a[i];
            }
        }
        cout<<sum;
    }
    if (m==2)
    {
        sum=a[1]&a[2];
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (i!=j)
                {
                    if (a[i]&a[j]>sum)
                    {
                        sum=a[i]&a[j];
                    }
                }
            }
        }
        cout<<sum;
    }

    return 0;
}
