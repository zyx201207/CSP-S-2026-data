#include <bits/stdc++.h>
#define  cin in
#define  cout out
using namespace std;
ifstream in("crystal.in");
ofstream out("crystal.out");
long long n, m, a[50000];
int main()
{
    cin >> n >> m;
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long add = 0, jia = 1;

    long long ans = 0, ad = 1;
    while (m >= ans)
    {
        ans = 0;
        for (long long qqqq = 0; qqqq <= ad; qqqq++)
        {
            ans += a[ad] - a[qqqq];
            a[qqqq] = a[ad];
        }
        // if (m >= ans)
        // {
        //     m -= ans;
        //     ad++;
        // }
        m -= ans;
        ad++;
        if (a[ad] == a[ad + 1])
        {
            ad++;
        }
    }
    cout << ad;

    // while (n >= jia)
    // {
    //     n -= jia;
    //     jia++;
    //     add++;
    // }
    // cout << add;
}
