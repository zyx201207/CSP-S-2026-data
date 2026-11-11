#include <bits/stdc++.h>
using namespace std;


int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s = "";
    int q;
    char w;
    for (int i = 1;i <= n;i++)
    {
        cin >> q >> w;
        while(q--)
        {
            s += w;
        }
    }
    int ds = s.size(),cnt = 0;
    for (int i = 0;i <= ds / 2 - 1;i++)
    {
        if (s[i] != s[ds - 1 - i])
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
