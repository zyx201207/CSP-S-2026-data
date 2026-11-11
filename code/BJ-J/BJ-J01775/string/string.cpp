#include <bits/stdc++.h>
using namespace std;
int n,x,shu;
char m;
int num,sum;
int z[25],f[25];
string s;
int main()
{
    freopen ("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        cin >> x >> m;
        shu += x;
        for (int j = 0;j < x;j++)
        {
            s[j] = m;
        }
    }
    for (int i = shu;i>= 0;i--)
    {
        f[i] = s[i];
    }
    num = shu / 2;
    for (int i = 0;i < num;i++)
    {
        if (f[i] != s[i])
        {
            sum++;
        }
    }
    cout << sum;
    return 0;
}
