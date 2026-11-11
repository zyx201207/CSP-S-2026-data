#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ll n = 0, sum = 0;
    cin >> n;
    string s;
    for(int i = 1; i <= n; i++)
    {
        ll x = 0;
        cin >> x;
        char y;
        cin >> y;
        while(x--)
        {
            s += y;
        }
    }
    ll len = s.size();
    for(int i = 0; i < len/2; i++)
    {
        if(s[i] != s[n - i])
        {
            sum++;
        }
    }
    cout << sum;
    return 0;
}
