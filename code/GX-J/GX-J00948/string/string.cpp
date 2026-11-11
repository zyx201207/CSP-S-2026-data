#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,cnt = 0;
    string b,s = "";
    cin >> n;
    for(int i = 1;i <= n;i++)

    {
        cin >> a;
        cin >> b;
        for(int j = 1;j <= a;j++)
        {
            s += b;
        }
    }
    if(n == 1)
    {
        cout << 0;
    }
    for(int i = 0;i < s.size();i++)
    {
        for(int j = s.size()-1;j >= 0;j--)
        {
            if((s[i] != s[j]) && (i != j))
            {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
