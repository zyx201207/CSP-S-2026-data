#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005],d[2000005],sum = 0;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    for (int i = 1;i <= t;i++)
    {
        sum = 0;
        cin >> n >> d;
        for (int j = 1;j <= n;j++) cin >> x[j];
        bool A = true;
        int cha = abs(x[1] - x[2]);
        for (int j = 1;j <= n - 1;j++)
        {
            if (abs(x[j] - x[j + 1]) != cha)
            {
                A = false;
                break;
            }
        }
        if (A == true)
        {
            for (int j = 1;j <= n;j++)
            {
                sum += 1;
            }
        }
        cout << sum << "\n";
    }
}
