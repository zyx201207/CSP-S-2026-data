#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005],sum,rt[200005],number;
long long num = 0;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i<=n; i++)
    {
        cin >> a[i];
    }
    if(m == 1)
    {
        for(int p = 1; p<=n; p++)
        {
            sum = max(sum,a[p]);
        }
        cout << sum;
        return 0;
    }
    if(m == n)
    {
        number = a[1];
        for(int e = 2; e<=n; e++)
        {
            number = a[e] & number;
        }
        cout << number;
        return 0;
    }
    if(m == n - 1)
    {
        for(int zz = 1; zz<=n; zz++)
        {
            sum = min(sum,a[zz]);
        }
        long long ser;
        if(sum == a[1])
        {
            ser = a[2];
            for(int yy = 2; yy<=n; yy++)
            {

                ser = a[yy] & ser;

            }
        }
        else
        {
            for(int yy = 1; yy<=n; yy++)
            {

                if(a[yy] != sum)
                {
                    ser = a[yy] & ser;
                }
            }
        }
        cout << ser;
        return 0;
    }
    rt[1] = a[1];
    for(int j = 1; j<=n; j++)
    {
        for(int r = j + 1; r<=n; r++)
        {
            rt[j] = max(a[j] & a[r],rt[j]);
        }

    }
    long long ghgh;
    for(int q = 1; q<=n; q++)
    {

        ghgh = max(ghgh,rt[q]);
    }
    cout << ghgh;
    return 0;

}
