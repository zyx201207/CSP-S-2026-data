#include <bits/stdc++.h>
using namespace std;

long long n, a[200005], len = 0, ans = 0;
char c[200005];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    for(long long i = 1; i <= n; i++)
    {
        scanf("%d %c", &a[i], &c[i]);
        len += a[i];
    }
    long long i = 1;
    long long j = n;
    long long l = a[i], r = a[j];
    while(1)
    {
        // cout << l << " " << r << endl;
        if(c[i] == c[j])
        {
            if(l > r)
            {
                l -= r;
                r = 0;
            }
            else if(l < r)
            {
                r -= l;
                l = 0;
            }
            else
            {
                l = 0;
                r = 0;
            }
        }
        else
        {
            if(l > r)
            {
                l -= r;
                ans += r;
                r = 0;
                // cout << 1 << endl;
            }
            else if(l < r)
            {
                r -= l;
                ans += l;
                l = 0;
                // cout << 2 << endl;
            }
            else
            {
                ans += min(l, r);
                l = 0;
                r = 0;
                // cout << 3 << endl;
            }
        }
        // cout << "ans: " << ans << endl;
        if(l == 0)
        {
            i++;
            l = a[i];
        }
        if(r == 0)
        {
            j--;
            r = a[j];
        }
        if(i >= j) break;
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

