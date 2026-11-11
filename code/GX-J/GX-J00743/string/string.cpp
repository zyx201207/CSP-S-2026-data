#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a,cnt = 0;
    char c;
    string s = "",l = "",r = "";
    cin>>n;
    for (long long i = 1; i <= n; i++)
    {
        cin>>a>>c;
        for (int j = 1; j <= a; j++)
        {
            s += c;
        }
    }
    for (long long i = 0; i <= s.size() / 2 - 1; i++)
    {
        l += s[i];
    }
    for (long long i = s.size() / 2 + 1; i <= s.size() - 1; i++)
    {
        r += s[i];
    }
    for (long long i = 0; i <= l.size() - 1; i++)
    {
        if (l[i] != r[i])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
