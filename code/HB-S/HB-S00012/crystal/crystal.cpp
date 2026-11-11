#include <bits/stdc++.h>
using namespace std;



int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    const int MyMAX = 500009;
    long long a[MyMAX] = {};
    long long n,m;
    cin >> n >> m;
    for (long long i = 0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    bool f = true;
    long long xuan = -1e9;
    long long i = n - 1;
    for (;i>=1;i--)
    {
        f = true;
        long long d = a[i];
        long long sum = 0;
        long long j = i - 1;
        for (;j>=0;j--)
        {
            if (sum + (d - a[j]) <= m)
            {
                sum += (d - a[j]);
            }
            else
            {
                f = false;
                continue;
            }
        }
        if (f == true)
        {
            xuan = max(xuan,i+1);
        }
    }
    cout << xuan << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
