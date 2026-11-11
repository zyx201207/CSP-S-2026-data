#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n, a;
    string s, m;
    int x = 0, y;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> s;
        for(int j = 1; j <= a; j++)
        {
            m += s;
        }
    }
    y = m.length();
    for (int i = 0; i < y; i++)
    {
        if (m[i] == m[y-1-i])
        {
            continue;
        }
        else
        {
            m[i] == m[y-1-i];
            x++;
        }
    }
    cout << x;
    return 0;
}
