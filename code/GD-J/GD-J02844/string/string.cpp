#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;


/*
abc
cbc
aba

*/

struct ss{
    char c;
    unsigned long long rrange;
}a[200009];
unsigned long long n;
unsigned long long lastc ;
unsigned long long slen = 0;


unsigned long long findiff(char c, unsigned long long l,unsigned long long r)
{
    unsigned long long currentx = lastc;
    unsigned long long current = slen;
    unsigned long long cctv = 0;
    for (unsigned long long x = currentx;x >= 1;x--)
    {
        unsigned long long em = current - a[x].rrange;
        if (a[x].c == c) continue;
        if (l <= em && current <= r)
        {
            // l -- [em current] -- r
            cctv += a[currentx].rrange;
        }
        else if (l <= em)
        {
            // l -- [em r current] --
            cctv += current - r;
        }
        else if (current <= r)
        {
            // [em l current] -- r
            cctv += current - l;
        }
    }
    return cctv;
}

/*

aaabb bcccc
aaabb bcaaa

3
3 a
3 b
4 c
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;

    for (int i = 1;i <= n;i++)
    {
        cin >> a[i].rrange >> a[i].c;
        slen +=a[i].rrange;
    }
    unsigned long long bef = 0;
    int x = 1;
    lastc = x;
    unsigned long long ct = 0;
    while (x <= n)
    {
        unsigned long long xl = bef;
        unsigned long long xr = bef + a[x].rrange;
        unsigned long long rxl = slen - xr+1;
        unsigned long long rxr = slen - xl;
        if (xl > (slen >> 1)) break;
        ct += findiff(a[x].c,rxl,rxr);
        bef = xr;
        x++;
    }
    cout << ct;
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
