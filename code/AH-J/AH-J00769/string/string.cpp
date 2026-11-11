#include <bits/stdc++.h>
using namespace ctd;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a[1000000005],sum = 0,sum1 = 0,num == 0,num1 == 0;
    cin >> n;
    string b,s,l,r;
    for (int i = 0;i < n;i++)
    {
        cin >> a[i] >> b[i];
    }
    for (int i = 0;i < n;i++)
    {
        num += a[i];
    }
    for (int i = 1;i < n;i++)
    {
        if (a[i] == a[i - 1])
            sum1 = 1;
        else
            sum1 = 2;
    }
    if (sum1 == 2)
    {
        for (int i = 0;i < num;i++)
        {
            for (int j = 0;j < a[i];j++)
            {
                s[j + num1] == b[i];
            }
            num1 += a[i];
        }
        l = s[0];
        r = s[num - 1]
        for (int i = 0;i < num / 2;i++)
        {
            if (l != r)
                sum++;
            l = s[i + 1];
            r = s[num - 1 - i - 1];
        }
    }
    else
    {
        l = b[0];
        r = b[n - 1];
        for (int i = 0;i < n;i++)
        {
            if (l != r)
                sum += a[i];
            l = b[i + 1];
            r = b[n - 1 - i - 1];
        }
    }
    cout << sum;
    return 0;
}
