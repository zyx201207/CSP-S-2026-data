#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
long long a[200007];
int h,t;
char c[200007];
ll tot;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1; i <= n ; i++)
    {
        scanf("%lld %c",&a[i],&c[i]);
    }
    h = 1;
    t = n;
    while(h < t)
    {
        if(c[h] == c[t])
        {
            if(a[h] > a[t])
            {
                a[h] = a[h] - a[t];
                t--;
            }
            else if(a[h] < a[t])
            {
                a[t] = a[t]- a[h];
                h++;
            }
            else
            {
                t--;
                h++;
            }
        }
        else
        {
            if(a[h] > a[t])
            {
                tot += a[t];
                a[h] = a[h] - a[t];
                t--;
            }
            else if(a[h] < a[t])
            {
                tot += a[h];
                a[t] = a[t]- a[h];
                h++;
            }
            else
            {
                tot += a[t];
                t--;
                h++;
            }
        }
    }
    printf("%lld",tot);
    return 0;
}