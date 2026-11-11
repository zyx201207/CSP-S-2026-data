#include <bits/stdc++.h>
using namespace std;
bool isstring(string s)
{
    for (int i = 1;i <= s.size() / 2;i++)
    {
        if (s[i] != s[s.size()+1-i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string k;
    string t[10000000];
    for (int i = 1;i <= n;i++)
    {
        cin >> t[i];
        k += t[i];
    }
    if (isstring(k))
    {
        cout << 0;
        return 0;
    }
    else
    {
        cout << 1;
    }
    return 0;
}
