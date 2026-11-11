#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N];
bool check1()
{
    for (int i = 1; i <= n; i++)
        if (a[i] != i)
            return false;
    return true;
}
bool check2()
{
    long long d=a[2]-a[1];
    for (int i = 3; i <= n; i++)
        if (a[i]-a[i-1] != d)
            return false;
    return true;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long i,j;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1,a+1+n);
    if (n <= 5000)
    {
        long long ans=0;
        for (i = 1; i <= n; i++)
        {
            long long cnt=0,tmp=m;
            for (j = i; j >= 1; j--)
            {
                if (tmp < a[i]-a[j])
                    break;
                tmp -= (a[i]-a[j]);
                cnt++;
            }
            ans = max(ans,cnt);
        }
        cout << ans;
    }
    else
    {
        if (max(abs(a[1]),abs(a[n])) <= 100)
        {
            long long ans=0;
            for (i = a[1]; i <= a[n]; i++)
            {
                long long cnt=0,tmp=m;
                for (j = i; j >= 1; j--)
                {
                    if (a[i] < a[j])
                        continue;
                    if (tmp < a[i]-a[j])
                        break;
                    tmp -= (a[i]-a[j]);
                    cnt++;
                }
                ans = max(ans,cnt);
            }
            cout << ans;
        }
        else if (check1())
        {
            for (i = n; i >= 1; i--)
                if (i*(i-1)/2 <= m)
                    return cout << i, 0;
        }
        else if (check2())
        {
            long long d=a[2]-a[1];
            for (i = n; i >= 1; i--)
                if (d*i*(i-1)/2 <= m)
                    return cout << i, 0;
        }
        else
        {
            long long ans=0;
            for (i = n/2-1000; i <= n/2+1000; i++)
            {
                long long cnt=0,tmp=m;
                for (j = i; j >= 1; j--)
                {
                    if (a[i] < a[j])
                        continue;
                    if (tmp < a[i]-a[j])
                        break;
                    tmp -= (a[i]-a[j]);
                    cnt++;
                }
                ans = max(ans,cnt);
            }
            cout << ans;
        }
    }
    return 0;
}