#include <bits/stdc++.h>
using namespace std;
string zhuan(long long x, long long y)
{
    string sum = "", sum1 = "";
    while (x != 0)
    {
        sum = (char)(x % 2 + '0') + sum;
        x /= 2;
    }
    while (y != 0)
    {
        sum1 = (char)(y % 2 + '0') + sum1;
        y /= 2;
    }
    for (long long i = max(sum.size(), sum1.size()); i >= 0; ++i)
    {
        if (sum[i] == 1 && sum1[i] == 1)
        {
            ans = ans * 10 + 1;
        }
    }
}
int main()
{
    freopen(and.in, "r", stdin);
    freopen(and.out, "w", stdout);
    cout << zhuan(6);
    return 0;
}
