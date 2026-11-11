#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
#define ull unsigned long long
#define N 500005
using namespace std;

ll rd(){char c=getchar();ll f=1,x=0;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0',c=getchar();}return f*x;}

ll n, m, a[N], res, s[N];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    // cin >> n >> m;
    n = rd(), m = rd();
    for (int i = 1; i <= n; i++) a[i] = rd();
    sort(a+1, a+1+n);
    for (int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
    ll res = -1;
    for (int i = 1; i <= n; i++)
    {
        ll l = 1, r = i, ans = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (a[i]*(i-mid+1)-(s[i]-s[mid-1]) <= m)
                ans = mid, r = mid-1;
            else l = mid+1;
        }
        res = max(res, i-ans+1);
    }
    cout << res;
    return 0;
}
/*
g++ crystal.cpp -std=c++14 -O2 -o crystal && time ./crystal
*/