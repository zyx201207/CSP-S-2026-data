#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
int n, a[N], d[N]; ll m, sum, ans; bool f=1, kf=1;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        if(a[i] != i) f=0;
    }
    sort(a+1, a+n+1);
    for(int i=1; i<n; i++)
    {
        d[i] = a[i+1] - a[i];
        if(i != 1 && d[i] != d[i-1]) kf=0;
    }
    if(f) //A
    {
        int cnt=0;
        for(int i=1; i<=n; i++)
        {
            m -= i;
            cnt++;
            if(m < 0) break;
        }
        cout << cnt << '\n'; return 0;
    }
    if(kf) //B
    {
        int cnt=0;
        for(int i=1; i<=n; i++)
        {
            m -= i * d[2];
            cnt++;
            if(m < 0) break;
        }
        cout << cnt << '\n'; return 0;
    }
    for(int i=1; i<=n; i++)
    {
        ll m_cpy = m, cnt=1;
        for(int j=i+1; j<=n; j++)
        {
            sum += d[j-1];
            m_cpy -= (d[j-1] ? sum : 0);
            cnt++;
            if(m_cpy <= 0)
            {
                m_cpy += sum;
                cnt--;
                break;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}
