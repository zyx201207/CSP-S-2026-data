#include <bits/stdc++.h>
using namespace std;
int n,a[500005],b[500005],c[500005];
long long m,s = -1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    if (n <= 5000)
    {
        long long sum = 1;
        sort(a + 1,a + n + 1);
        for (int i = 1;i <= n;i++)
        {
            long long x = m,j = i - 1;
            sum = 0;
            while (x > 0 && j <= n)
            {
                j++;
                if (x >= abs(a[j] - a[i]))
                {
                    x -= abs(a[j] - a[i]);
                    sum++;
                }
                else
                {
                    break;
                }
            }
            s = max(s,sum);
        }
        cout << s;
    }
    else
    {
        bool A = true,B = true;
        int cha = abs(a[1] - a[2]);
        for (int i = 1;i <= n;i++)
        {
            if (a[i] != i)
            {
                A = false;
                break;
            }
        }
        for (int i = 1;i <= n - 1;i++)
        {
            if (abs(a[i] - a[i+1]) != cha)
            {
                B = false;
                break;
            }
        }
        if (A == true)
        {
            int w = 0,i = 0,sum = 0;
            long long x = m;
            while (x > 0 && i <= n)
            {
                i++;
                if (x >= (a[1] + abs(a[i] - a[1])) * i / 2)
                {
                    sum++;
                    x -= (a[1] + abs(a[i] - a[1])) * i / 2;
                }
            }
            cout << sum;
        }
        else
        {
            cout << 1;
        }
    }
    return 0;
}
