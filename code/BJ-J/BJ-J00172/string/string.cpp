#include <bits/stdc++.h>
using namespace std;
int c[200005], cnt1;
char ch[200005];
string s;
bool check(string sss)
{
    for(int i = 0; i < sss.size()/2; i++)
    {
        if(sss[i] != sss[sss.size()-1-i])return 0;
    }
    return 1;
}
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << 0;
        return 0;
    }
    if(n == 2)
    {
        int a, b;
        char ca, cb;
        cin >> a >> ca;
        cin >> b >> cb;
        for(int i = 0; i < a; i++)s += ca;
        for(int i = a; i < a+b; i++)s += cb;
        if(check(s))cout << 0;
        else cout << min(a, b);
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> c[i] >> ch[i];
        if(ch[i] == 1)cnt1++;
    }
    if(cnt1 == n)
    {
        cout << n;
        return 0;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= c[i]; j++)
            s += ch[i];
    if(check(s))cout << 0;
    return 0;
}
