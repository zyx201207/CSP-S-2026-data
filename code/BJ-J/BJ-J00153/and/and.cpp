#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n, m, a[100005];
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    string o[100005];
    for (int i = n;i >= m;i--)
    {
        string p;
        long long s = 1;
        while(true)
        {
            if (a[i] == 0)
            {
                break;
            }
            p += a[i] % 2;
        }
        string b;
        for (int j = p.size();j >= 0;j--)
        {
            b += p[j];
        }
        o[i] = b;
    }
    for (int i = 1;i < m;i++)
    {
        string f = o[i], w = o[i+1],k;
        for (int j = 1;j <= f.size();j++)
        {
            for (int z = 1;z <= w.size();z++)
            {
                if (f[z] == w[z])
                {
                    k += '0';
                }
                else
                {
                    k += '1';
                }
            }
        }
        o[i+1] = k;
    }
    cout << o[m-1];
    return 0;
}
