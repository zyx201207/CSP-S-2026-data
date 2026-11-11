#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n, m, a[N], b[N];

long long read()
{
    long long w = 1, x = 0; char ch;
    ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-') w *= -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * w;
}

bool check(int x)
{
    for(int i = x; i <= n; i++)
        if(a[i] * x - (b[i] - b[i - x]) <= m)
            return 1;
    return 0;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n = read();
    m = read();
    for(int i = 1; i <= n; i++)
        a[i] = read();
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
        b[i] = b[i - 1] + a[i];
    int l = 1, r = n;
    while(l < r)
    {
        int mid = (l + r + 1) / 2;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}
