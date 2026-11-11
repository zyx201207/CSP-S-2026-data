#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

long long b[N];

struct node
{
    long long x;
    int i;
};

node a[N];

int n;
long long m, m1, x;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m1;
    for(int i = 1;i <= n;i++)
    {
        scanf("%lld", &b[i]);
    }
    sort(b + 1, b + n + 1);
    /*for(int i = 1;i <= n;i++)
    {
        cout << b[i] << " ";
    }*/
    int nn = n;
    int i = 1;
    for(int j = 1;j <= nn;j++)
    {
        a[i].x = b[j];
        a[i].i = 1;
        if(b[j] == b[j - 1])
        {
            a[i - 1].i++;
            i--;
            n--;
        }
        i++;
        //cout << n << endl;
    }
    /*for(int i = 1;i <= n;i++)
    {
        cout << a[i].x << " " << a[i].i << "     ";
        ccn += a[i].i;
    }*/
    int ans = 1;
    int flag = 1;
    a[0].x = 1e18;
    for(int j = 1;j <= n;j++)
    {
        int i = j;
        m = m1;
        int cnt = a[i].i;
        while(m > 0 && i <= n)
        {
            x = a[i + 1].x - a[i].x;
            m -= (x * cnt);
            //cout << x << " " << i << " " << m << " " << j << " " << i * x * a[i].i << endl;
            i++;
            cnt += a[i].i;
        }
        if(m < 0)
        {
            cnt -= a[i--].i;
            //cout << "#" << j << " " << cnt << endl;
            m += x * cnt;
            //cout << x << " " << m << endl;
            cnt += max(m / x + a[i + 1].i - cnt, m / (a[i].x - a[j - 1].x));
            //cout << a[i].x << " " << a[j - 1].x << endl;
        }
        else
        {
            while(a[i + 1].x == a[i].x && i < n)
            {
                cnt += a[i + 1].i;
            }
        }
        if(cnt >= ans)
        {
            flag = j;
        }
        ans = max(ans, cnt);
        if(clock() * 1.0 / (1.0 * CLOCKS_PER_SEC) >= 0.998)
        {
            cout << ans << endl;
            return 0;
        }
    }
    cout << ans << endl;
    //cout << clock () * 1.0 / CLOCKS_PER_SEC << endl;
    return 0; 
}
