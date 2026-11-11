#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
int a[200005];
char c[200005];
struct Node
{
    int sum;
    char c;
};

vector <Node> l;
vector <Node> r;

signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    scanf("%lld", &n);
    int cnt = 0;

    for(int i = 1; i <= n; i++)
    {
        int x;
        char y;
        scanf("%lld %c", &x, &y);

        a[i] = x;
        c[i] = y;

        cnt += a[i];
    }

    int hafcnt = cnt / 2;
    bool flag = (cnt % 2 == 0);

    int p = 1;

    for(p; p <= n; p++)
    {
        if(hafcnt - a[p] > 0)
        {
            l.push_back({a[p], c[p]});
            hafcnt -= a[p];
        }
        else
        {
            break;
        }
    }

    if(flag)
    {
        l.push_back({hafcnt, c[p]});
        int num = a[p];

        num -= hafcnt;

        if(num != 0)
        {
            r.push_back({num, c[p]});
        }
    }
    else
    {
        l.push_back({hafcnt, c[p]});
        int num = a[p];

        num -= hafcnt;
        num -= 1;

        if(num != 0)
        {
            r.push_back({num, c[p]});
        }
    }

    p++;

    for(int i = p; i <= n; i++)
    {
        r.push_back({a[p], c[p]});
    }

    int ans = 0;

    int i = 0;
    int j = r.size() - 1;

    while(i < r.size() && j >= 0)
    {
        if(l[i].c == r[j].c)
        {
            if(l[i].sum > r[j].sum)
            {
                l[i].sum -= r[j].sum;
                j--;
            }
            else if(l[i].sum < r[j].sum)
            {
                r[j].sum -= l[i].sum;
                i++;
            }
            else
            {
                i ++;
                j--;
            }
        }
        else
        {
            if(l[i].sum > r[j].sum)
            {
                l[i].sum -= r[j].sum;
                ans += r[j].sum;
                j--;
            }
            else if(l[i].sum < r[j].sum)
            {
                r[j].sum -= l[i].sum;
                ans += l[i].sum;
                i++;
            }
            else
            {
                ans += l[i].sum;
                i ++;
                j--;
            }
        }
    }


    printf("%lld", ans);

    return 0;
}
