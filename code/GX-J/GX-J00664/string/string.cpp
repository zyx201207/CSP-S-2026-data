#include <bits/stdc++.h>
using namespace std;
long long cnt;
bool hw(string s)
{
    long long len = s.size() - 1;
    for(long long i = 0 ;i <= len / 2 ;i++)
    {
        if(s[i] != s[len - i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin >> n;
    string s;
    for(long long i = 1 ;i <= n ;i++)
    {
        long long m;
        cin >> m;
        string c;
        cin >> c;
        for(long long j = 1 ;j <= m ;j++)
        {
            s += c;
        }
    }
    long long len = s.size() - 1;
    if(hw(s))
    {
        cout << "0";
        return 0;
    }
    long long i = 0;
    while(hw(s) == 0)
    {
        if(s[i] != s[len - i])
        {
            s[len - i] = s[i];
            cnt++;
        }
        i++;
    }
    cout << cnt;
    return 0;
}
