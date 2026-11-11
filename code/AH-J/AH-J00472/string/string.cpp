#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n ,fr = 1 ,ba = 0;
long long a[N] ,ans = 0 ,tail = 0 ,head = 1 ,mid/* ,l[N] ,r[N]*/;
char c[N];

int main ()
{
    freopen ("string.in" ,"r" ,stdin);
    freopen ("string.out" ,"w" ,stdout);
    bool ji;
    scanf ("%d" ,&n);
    for (int i = 1;i <= n;i++)
    {
        scanf ("%lld %c" ,&a[i] ,&c[i]);
        //l[i] = tail + 1;
        tail += a[i];
        //r[i] = tail;
        ba++;
    }
    if (tail % 2) ji = true;
    else          ji = false;
    mid = (head + tail) / 2;
    //printf ("%d %d %d\n" ,tail ,ba ,mid);
    while (((ji && head < mid && tail > mid) || (!ji && head <= mid && tail > mid)) && ba > fr)
    {
        long long fd;
        bool fj = false ,bj = false;
        if (a[ba] < a[fr])
        {
            fd = a[ba];
            bj = true;
        }
        else if (a[ba] == a[fr])
        {
            fd = a[ba];
            fj = true;
            bj = true;
        }
        else
        {
            fd = a[fr];
            fj = true;
        }
        head += fd;
        tail -= fd;
        if (ji)
        {
            if (head > mid) fd -= head - mid;
            if (tail < mid) fd -= mid - tail;
        }
        else
        {
            if (head > mid + 1) fd -= head - mid - 1;
            if (tail < mid) fd -= mid - tail;
        }
        if (c[ba] != c[fr])
        {
            ans += fd;
        }
        if (fj) fr++;
        else a[fr] -= fd;
        if (bj) ba--;
        else a[ba] -= fd;
        //printf ("%d\n" ,fd);
    }
    printf ("%lld\n" ,ans);
    return 0;
}
/*
3
2 a
2 b
1 c
*/
