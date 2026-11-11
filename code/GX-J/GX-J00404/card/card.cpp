#include <bits/stdc++.h>
using namespace std;
int n,m,num[500005],a[300005];
string s;
bool check(char x)
{
    for(int i = 0;i < s.size();i++)
    {
        if(s[i] == x) return false;
    }
    return true;
}
int pts(char x)
{
    for(int i = 0;i < s.size();i++)
    {
        if(s[i] == x) return i;
    }
}
void hass()
{
    for(int i = 0;i < s.size();i++)
    {
        a[int(s[i] - 48)]+= 1;
    }
}
int main()
{
    freopen("card3.in","r",stdin);
    freopen("card3.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> num[i];
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = i;j <= n;j++)
        {
            if(check(char(num[j] + 48)))
            {
                s += char(num[j] + 48);
            }
            else
            {
                int f = pts(char(num[j] + 48));
                s.erase(f,s.size() - f);
                s += char(num[j] + 48);
            }
        }
        hass();
        s = "";
    }
    for(int i = 1;i <= m;i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
