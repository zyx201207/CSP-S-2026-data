#include <bits/stdc++.h>
using namespace std;
string s,new_s;
char c;
int n,a;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> a >> c;
        for(int j = 0;j < a;j++) s += c;
    }
    new_s = s;
    reverse(new_s.begin(),new_s.end());
    if(s == new_s)
    {
        cout << "0";
        return 0;
    }
    int cnt = 0;
    int len = s.size();
    for(int i = 0;i < len;i++)
    {
        if(s[i] != new_s[i])
        {
            cnt++;
            new_s[i] = s[i];
            string tmp = new_s;
            reverse(tmp.begin(),tmp.end());
            if(tmp == new_s)
            {
                cout << cnt;
                return 0;
            }
        }
    }
    cout << cnt;
    return 0;
}
