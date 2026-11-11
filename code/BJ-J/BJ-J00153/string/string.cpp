#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n, a[100005];
    char b[100005];
    cin >> n;
    for (long long i = 0;i < n;i++)
    {
        cin >> a[i] >> b[i];
    }
    long long t = 0, s, m, q, p;
    for (long long i = 0;i <= n/2;i++)
    {
        for (long long j = n-1;j > n/2;j--)
        {
            if (s == 0)
            {
                s = a[i];
                q = i;
            }
            if (m == 0)
            {
                m = a[j];
                p = j;
            }
            if (b[q] != b[p])
            {
                t++;
            }
            s--;
            m--;
        }
    }
    cout << t;
    return 0;
}
