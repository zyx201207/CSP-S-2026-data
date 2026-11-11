#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long n, l, r, ans = 0;
struct st{
    int a;
    char c;
}s[N];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >>n;
    for (long long i = 1; i <= n; i++) cin >>s[i].a >>s[i].c;
    l = 1, r = n;
    while (l != r)
    {
        long long m = min(s[l].a, s[r].a);
        if (s[l].c != s[r].c) ans += m;
        s[l].a -= m;
        s[r].a -= m;
        if (s[l].a == 0) l++;
        else r--;
    }
    cout <<ans;
    return 0;
}
