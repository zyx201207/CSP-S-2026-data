#include <bits/stdc++.h>
using namespace std;
long long n, l = 1, ans;
struct node
{
    long long l, r, len;
    char c;
} a[200005];
char v[200005];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        long long len;
        char x;
        cin >> len >> x;
        a[i] = {l, l + len - 1, len, x};
        l += len;
    }
    l--;
    /*for (int i = 1; i <= n + 1; i++)
    {
        printf("%lld %lld %c\n", a[i].l, a[i].r, a[i].c);
    }
    cout << endl;
    if(l&1)
        for (int i = 1; i <= n;i++)
        {
            //cout << "%";
            if(a[i].l==l/2+1)
            {
                a[i].l++;
                break;
            }
            if(a[i].r>l/2+1&&a[i].l<l/2+1)
            {
                for (int j = n + 1; j > i;j--)
                    a[j] = a[j - 1];
                a[i + 1] = {l / 2 + 2, a[i].r, a[i].c};
                a[i].r = l / 2;
                break;
            }
            else if(a[i].r==l/2+1)
            {
                a[i].r--;
                break;
            }
        }
    else
        for (int i = 1; i <= n;i++)
        {
            if(a[i].r>l/2&&a[i].l<=l/2)
            {
                //cout << "%";
                for (int j = n + 1; j > i;j--)
                    a[j] = a[j - 1];
                a[i + 1] = {l / 2+1, a[i].r, a[i].c};
                a[i].r = l / 2;
                break;
            }
            else if(a[i].r==l/2)
                break;
        }
    for (int i = 1; i <= n+1;i++)
    {
        printf("%lld %lld %c\n", a[i].l, a[i].r, a[i].c);
    }
    int li = 1, ri = n;
    if(a[n+1].c>='A')
        ri++;
    while (li <= ri)
    {
        if(v[ri]=='l')
            break;
        if(v[li]=='r')
            break;
        v[li] = 'l';
        v[ri] = 'r';
        if(a[li].r<n-a[ri].l+1)
        {
            if(a[li].c!=a[ri].c)
                ans += a[li].r - a[li].l + 1;
            a[ri].r = n - a[li].r;
            li++;
        }
        else if(a[li].r==n-a[ri].l+1)
        {
            if (a[li].c != a[ri].c)
                ans += a[li].r - a[li].l + 1;
            li++;
            ri--;
        }
        else
        {
            if (a[li].c != a[ri].c)
                ans += a[ri].r - a[ri].l + 1;
            a[li].l = n - a[ri].r + 2;
            ri--;
        }
    }*/
    ans = l / 2;
    int li = 1, ri = n;
    while (li < ri)
    {
        if (a[li].len < a[ri].len)
        {
            if (a[li].c == a[ri].c)
                ans -= a[li].len;
            a[ri].len -= a[li].len;
            a[ri].r = a[ri].l + a[ri].len - 1;
            li++;
        }
        else if (a[li].len == a[ri].len)
        {
            if (a[li].c == a[ri].c)
                ans -= a[li].len;
            li++;
            ri--;
        }
        else
        {
            if (a[li].c == a[ri].c)
                ans -= a[ri].len;
            a[li].len -= a[ri].len;
            a[li].l = a[li].r - a[li].len + 1;
            ri--;
        }
    }
    // cout <<li<<" "<<ri<<" "<< ans << endl;
    if (li == ri)
    {
        // printf("%lld %lld %lld %c\n", a[li].l, a[li].r, a[li].len, a[li].c);
        long long x = l / 2 - a[li].l, y = a[li].r - l / 2 - 1;
        ans -= min(x, y) + 1;
    }
    cout << min(l / 2, ans) << endl;
    return 0;
}
