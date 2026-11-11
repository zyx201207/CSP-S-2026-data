#include <bits/stdc++.h>
using namespace std;

long long n,s[510000];
long long m,a[510000];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++)
    {
        s[i] = s[i - 1] + a[i];
    }
    long long ams = 0;
    for(long long i = 1;i <= n;i++)
    {
        //(i - 1) * a[i] - s[i - 1]
        long long l = 0,r = i;
        while(l + 1 < r)
        {
            long long mid = (l + r) / 2;
            long long x = a[i] * (i - mid + 1);
            x -= s[i];
            x += s[mid - 1];
            if(x <= m)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        ams = max(ams,i - r + 1);
    }
    cout << ams;
}
