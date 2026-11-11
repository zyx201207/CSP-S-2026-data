#include <bits/stdc++.h>
using namespace std;
long long a[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int n;
    long long m;
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
    }

    sort(a + 1,a + n + 1);

    long long x = 1;
    long long ans1 = 0;
    for(int i = 1;i <= n;i ++)
    {
        if(a[i] == a[i - 1])
        {
            x ++;
            ans1 = max(ans1,x);
        }
        else
        {
            x = 0;
        }
    }

    long long ans2 = 1;
    for(int i = 2;i <= n;i ++)
    {
        long long sum = 0;
        for(int j = 1;j <= i;j ++)
        {
            sum += (a[i] - a[j]);
        }
        if(sum <= m)
        {
            ans2 = i;
        }
    }

    cout << max(ans1,ans2);

    return 0;
}
