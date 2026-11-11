#include <bits/stdc++.h>
using namespace std;

int a[200005] = {};
int b[3005];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    if (m == 1)
    {

        cout << n;
        return 0;
    }
    for (int i = 1;i <= n;i++)
    {
        string s = "";
        for (int j = i;j <= n;j++)
        {
            char ch = a[j] + '0';
            if (s.find(ch) != string::npos)
            {
                int q = s.find(ch);
                s.erase(q);
            }
            s += ch;
        }
        int ds = s.size();
        for (int j = 0;j <= ds - 1;j++)
        {
            int w = s[j] - '0';
            b[w]++;
        }
    }
    for (int i = 1;i <= m;i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}
