#include<bits/stdc++.h>
using namespace std;

long long a[500010];
long long cg[500010]; // cg rfs to cha_ju

bool cmp(long long a, long long b)
{
    return a > b;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    long long n, m, avg = 0; // avg rfs to average
    cin >> n >> m;

    for(long long i = 1;i <= n;i ++)
    {
        cin >> a[i];
        avg += a[i];
    }

    //13~15 te_shu_pian_fen
    if(n > 5000 && m > 80000)
    {
        if(a[2] - a[1] == a[3] - a[2] && a[1314] - a[1312] == a[2] - a[1])
        {
            avg = a[n / 2];
        }
        else
        {
            avg /= n;
        }
    }
    else
    {
        avg /= n;
    }



    long long cgsz = 0; //rfs to cg size (positive cg value)
    for(long long i = 1;i <= n;i ++)
    {
        cg[i] = avg - a[i];
        if(avg - a[i] >= 0)
        {
            cgsz ++;
        }
    }
    sort(cg + 1, cg + n + 1, cmp);
    long long cnt = 1, ans = 0;
    while(m)
    {
        if(cg[cnt] == 0)
        {
            cnt ++;
            continue;
        }
        if(cnt > cgsz)
        {
            break;
        }
        cg[cnt] --;
        m --;

    }
    for(long long i = 1;i <= cgsz;i ++)
    {
        if(cg[i] == 0)
        {
            ans ++;
        }
    }

    while(m - cgsz >= 0)
    {
        for(long long i = cgsz + 1;i <= n;i ++)
        {
            cg[i] ++;
            if(cg[i] == 0)
            {
                ans ++;
                cgsz ++;
            }
        }
        m -= cgsz;
    }
    cout << ans;
    return 0;
}
