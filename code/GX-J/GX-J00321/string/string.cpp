#include <bits/stdc++.h>
using namespace std;
string a = "";
char b;
long long n,x,sum=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> x >> b;
        for (int j = 1;j <= x;j++)
        {
            a += b;
        }
    }
    for (int i = 0;i < a.size() / 2 - 1;i++)
    {
        if (a[i] != a[a.size() - i - 1])
        {
            sum++;
        }
    }
    cout << sum;
    return 0;
}
