#include <bits/stdc++.h>
using namespace std;
long long a[200010];
int main()
{
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    int n , m;
    cin >> n >> m;
    bool flag = 1;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] >= 4) flag = 0;
    }
    long long ans = 0 , sum = 0;
    if(m == 1)
    {
        sort(a + 1 , a + n + 1);
        cout << a[n] << endl;
    }
    else if(m == n)
    {
        ans = a[1];
        for(int i = 2; i <= n; i++)
        {
            ans = ans & a[i];
        }
        cout << ans << endl;
    }
    else if(m == 2)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                ans = max(ans , a[i] & a[j]);
            }
        }
        cout << ans << endl;
    }
    else if(flag)
    {
        long long cnt1 = 0 , cnt2 = 0 , cnt3 = 0 , cnt0 = 0;
        for(int i = 1; i <= n; i++)
        {
            if(a[i] == 0) cnt0++;
            if(a[i] == 1) cnt1++;
            if(a[i] == 2) cnt2++;
            if(a[i] == 3) cnt3++;
        }
        if(cnt3 >= m) cout << 3 << endl;
        else if((cnt3 + cnt2) >= m) cout << 2 << endl;
        else if((cnt3 + cnt1) >= m) cout << 1 << endl;
        else cout << 0 << endl;
    }
    else{
        sort(a + 1 , a + n + 1);
        cout << a[n - m + 1] << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
