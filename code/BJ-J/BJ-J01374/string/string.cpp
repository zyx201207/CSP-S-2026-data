#include<bits/stdc++.h>
using namespace std;

int n;
struct node{
    long long cnt;
    char a;
}a[200010], b[200010], c[100010];
long long sum;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].cnt >> a[i].a;
        sum += a[i].cnt;
    }
    long long t = 0;
    int id = 0, x1 = 0, x2 = 0;
    if(sum % 2 == 1)
    {
        sum++;
        sum /= 2;
        for(int i = 1; i <= n; i++)
        {
            if(t + a[i].cnt >= sum && id == 0)
            {
                id = i;
                b[++x1] = {sum - t - 1, a[i].a};
                c[++x2] = {a[i].cnt - sum + t, a[i].a};
            }
            else if(id == 0)
            {
                b[++x1] = {a[i].cnt, a[i].a};
                t += a[i].cnt;
            }
            else c[++x2] = {a[i].cnt, a[i].a};
        }
    }
    else
    {
        sum /= 2;
        for(int i = 1; i <= n; i++)
        {
            if(t + a[i].cnt >= sum && id == 0)
            {
                id = i;
                b[++x1] = {sum - t, a[i].a};
                c[++x2] = {a[i].cnt - sum + t, a[i].a};
            }
            else if(id == 0)
            {
                b[++x1] = {a[i].cnt, a[i].a};
                t += a[i].cnt;
            }
            else c[++x2] = {a[i].cnt, a[i].a};
        }
    }
    int i1 = 1, i2 = x2;
    long long ans = 0;
    while(i1 <= x1 && i2 >= 1)
    {
        while(b[i1].cnt == 0) i1++;
        while(c[i2].cnt == 0) i2--;
        if(b[i1].a != c[i2].a)
        {
            if(b[i1].cnt == c[i2].cnt)
            {
                ans += b[i1].cnt;
                i1++;
                i2--;
            }
            else if(b[i1].cnt < c[i2].cnt)
            {
                ans += b[i1].cnt;
                c[i2].cnt -= b[i1].cnt;
                i1++;
            }
            else
            {
                ans += c[i2].cnt;
                b[i1].cnt -= c[i2].cnt;
                i2--;
            }
        }
        else
        {
            if(b[i1].cnt == c[i2].cnt)
            {
                i1++;
                i2--;
            }
            else if(b[i1].cnt < c[i2].cnt)
            {
                c[i2].cnt -= b[i1].cnt;
                i1++;
            }
            else
            {
                b[i1].cnt -= c[i2].cnt;
                i2--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}