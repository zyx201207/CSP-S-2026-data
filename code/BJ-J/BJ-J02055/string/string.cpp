#include <bits/stdc++.h>
using namespace std;

long long n, ans;

struct Node
{
    long long st, en;
    char c;
}a[200005];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    int lst = 0, tmp;
    for (int i = 1; i <= n; ++i)
    {
        cin >> tmp >> a[i].c;
        a[i].st = lst + 1;
        lst += tmp;
        a[i].en = lst;
    }
    int l = 1, r = n, i = 1;
    while(l != r)
    {
        if(i > lst / 2) break;
        if(a[l].en < i) ++l;
        if(a[r].st > lst - i + 1) --r;
        if(l == r) break;
        int len1 = a[l].en - i + 1;
        int len2 = lst -  i + 1 - a[r].st + 1;
        if(a[l].c != a[r].c) ans += min(len1, len2);
        i += min(len1, len2);
    }
    cout << ans << endl;
    return 0;
}
