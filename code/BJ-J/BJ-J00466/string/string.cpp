#include<bits/stdc++.h>
using namespace std;
int n,x,cnt;
char c;
string s,a;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> x >> c;
        for(int i = 1;i <= x;i++)
        {
            s += c;
        }
    }
    for(int i = 0;i < s.size() / 2;i++)
    {
        if(s[i] != s[s.size() - 1 - i])
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}