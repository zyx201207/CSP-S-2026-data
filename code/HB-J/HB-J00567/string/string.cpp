#include <bits/stdc++.h>
using namespace std;

int n, a;
string s;
char c;
long long ans, len;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %c", &a, &c);
        for (int j = 1; j <= a; j++)
            s += c;
        len += a;
    }
    for (long long i = 0; i <= (len - 1) / 2; i++)
    {
        
        if (s[i] != s[len - 1 - i])
            ans++;
    }
    printf("%lld\n", ans);
    return 0;
}