#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    long long n,m;
    long long a[500005]{};
    long long maxi = -INT_MAX;
    cin>>n>>m;
    if(m == 2)
    {
        for(long long i = 1;i <= n;i++)
        {
            cin>>a[i];
        }
        for(long long i  = 1;i <= n-1;i++)
        {
            for(long long j = i + 1;j <= n;j++)
            {
                int t = a[i] & a[j];
                if(t >= maxi)
                    maxi = t;
            }
        }
        cout<<maxi;
    }
    if(m == 3)
    {
        for(long long i = 1;i <= n;i++)
        {
            cin>>a[i];
        }
        for(long long i  = 1;i <= n-2;i++)
        {
            for(long long j = i + 1;j <= n-1;j++)
            {
                for(long long k = j + 1;k <= n;k++)
                {
                    int t = a[i] & a[j] & a[k];
                    if(t >= maxi)
                        maxi = t;
                }
            }
        }
        cout<<maxi;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
