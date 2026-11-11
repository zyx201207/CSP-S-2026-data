#include<bits/stdc++.h>
using namespace std;
int n;
long long m, a[100001];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
                if(m > 100000000)
                {
                    if (m / (a[1] - a[0]) < n / 2)
                    {
                        int ans = m / (a[1] - a[0]);
                        cout << ans;
                    }else
                    {
                        cout << n;
                    }
                    return 0;
                }
    sort(a, a + n);

    int ans = 0;
    while(m > 0)
    {
        int ai;
        long long ma = 100000000000000000;
        for (int i = 1; i < n; i++)
        {
            if(a[i] - a[i - 1] < ma and a[i] != a[i - 1])
            {
                ai = i;
                ma = a[i] - a[i - 1];
            }
        }
        if (m >= ma)
        {
            m -= ma;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    for (int i = 0; i < n; i++)
    {
        int ai = a[i], aj = i;
        int flag = 0;
        for(int j = i; j < n; j++)
        {
            if (a[j] == ai)
            {
                flag = 1;
                ans++;
                aj++;
            }else
            {
                break;
            }
            i = aj;
        }
        if (flag == 1)
        {

            ans++;
        }
    }
    cout << ans;
    return 0;
}
