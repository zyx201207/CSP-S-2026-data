#include <bits/stdc++.h>
using namespace std;
string s,s1;
int n;
int a;
char c;
int num;
int cnt;
bool is_huiwen(string b)
{
    for(int i = b.size()-1;i >= 0;i--)
    {
        s1[cnt] = b[i];
        cnt++;
    }
    for(int i = 0;i < s.size();i++)
    {
        if(b[i] != s1[i])
            return false;
    }
    return true;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a >> c;
        for(int j = 1;j <= a;j++)
        {
            s[num] = c;
            num++;
        }
    }
    if(is_huiwen(s))
    {
        cout << 0;
        return 0;
    }
    cout << s.size()/2;
    return 0;
}