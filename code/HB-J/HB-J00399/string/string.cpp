#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
int n,a[MAXN];
long long len,ans;
char c[MAXN];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i] >> c[i];
        len += a[i];
    }
    long long l = 1,r = len;
    int p1 = 1,p2 = n;
    while(l < r)
    {
        if(c[p1] != c[p2])
            ans += min(a[p1],a[p2]);
        if(a[p1] < a[p2])
        {
            l += a[p1];
            r -= a[p1];
            a[p2] -= a[p1];
            p1++;
        }
        else if(a[p1] > a[p2])
        {
            l += a[p2];
            r -= a[p2];
            a[p1] -= a[p2];
            p2--;
        }
        else
        {
            l += a[p1];
            r -= a[p2];
            p1++;
            p2--;
        }
    }
    cout << ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
