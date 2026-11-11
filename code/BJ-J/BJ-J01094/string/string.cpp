#include <bits/stdc++.h>
using namespace std;
bool isprime(int x)
{
    if(x < 2)
    {
        return 0;
    }
    for(int i = 2; i * i <= x; ++i)
    {
        if(x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int gcd(int a, int b)
{
    long long x = 2;
    long long ans = 1;
    while(!isprime(a) && !isprime(b) || a != 1 || b != 1 || x > min(a, b))
    {
        if(a % x == 0 && b % x == 0)
        {
            a /= x;
            b /= x;
            ans *= x;
        }
        else
        {
            ++x;
        }
    }
    return ans;
}
struct S
{
    long long a;
    string b;
}t[1000005];
int main()
{
    int n;
    cin >> n;
    string s;
    for(int i = 1; i <= n; ++i)
    {
        int a;
        string b;
        cin >> a;
        cin >> b;
        for(int j = 1; j <= a; ++j)
        {
            s += b;
        }
    }
    /*for(int i = 1; i <= n; ++i)
    {
        cin >> t[i].a;
        cin >> t[i].b;
    }
    for(int i = 1; i <= n; ++i)
    {
        int x = gcd(t[i].a, t[i+1].a);
        t[i].a /= x;
        t[i+1].a /= x;
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= t[i].a; ++j)
        {
            s += t[i].b;
        }
    }*/
    string ans, ans2;
    for(int i = 0; i < (s.size() + 1) / 2 - 1; ++i)
    {
        ans += s[i];
    }
    for(int i = (s.size() + 1) / 2; i <= s.size(); ++i)
    {
        ans2 += s[i];
    }
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < (s.size() + 1) / 2; i++)
    {
        if(ans2[i] != ans[i])
        {
            cnt1++;
        }
    }
    for(int i = 0; i < (s.size() + 1) / 2; i++)
    {
        if(ans[i] != ans2[i])
        {
            cnt2++;
        }
    }
    cout << min(cnt1, cnt2);
    return 0;
}