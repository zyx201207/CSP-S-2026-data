#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cs,t;
const int N = 500005;

ll a[N];

ll read()
{
    ll x = 0;
    int f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    return f * x;
}

void solve()
{
cin >> cs>>t;
while(t-->0)cout<<"0\n";
}

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    solve();
    return 0;
}
//100+44+[8,16]=[152,160]
//Lemon road, I'll love you 4 ever!
//hope 1=!!!
