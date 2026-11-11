#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct duan
{
    long long int len;
    char val;
    long long int s, e;//start id  end id
};

int n;
long long int bj[414514];
int bjlen;
duan a[214514];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    long long int f = 0;
    int i, j;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i].len >> a[i].val;
        a[i].s = f + 1;
        f += a[i].len;
        a[i].e = f;
        bj[++bjlen] = f;
        //cout << a[i].s <<" "<< a[i].e<<" " << bj[i] << endl;
    }
    a[n + 1] = {1, 'z', f + 1, f + 1};
    for (i = 1; i <= n; i++)
    {
        bj[++bjlen] = f - bj[i];
    }
    sort(bj + 1, bj + bjlen + 1);
    int qi = 1, hi = n;
    long long int ans = 0, last = 0;
    for (i = 2; i <= bjlen; i++)
    {
        if (a[qi].e < bj[i])
        {
            qi++;
        }
        if (a[hi].s > f - bj[i] + 1)
        {
            hi--;
        }
        if (a[qi].e + 1 > a[hi].s)
        {
            break ;
        }
                //cout << bj[i] << endl;

        if (a[qi].val != a[hi].val)
        {
            ans += bj[i] - last;
        }
        last = bj[i];
    }
    cout << ans << endl;
    return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
