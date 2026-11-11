#include <bits/stdc++.h>
using namespace std;
int b[10000000],a[100000000];
long long sum[1000000000];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++)
    {
        string s;
        for (int j = i;j <= n;j++)
        {
            s[j] = "0" + a[j];
            for (int k = 1;k <= s.size() - 1;k++)
            {
                if (s[k] == s[j])
                {
                    for (int l = k;l <= s.size()-1;s++)
                    {
                        s[l] = "(";
                    }
                }
            }
        }
        for (int j = 1;j <= s.size();j++)
        {
            if (s[j] = "(")
            {
                continue;
            }
            sum[s[j] - "0"]++;
        }
    }
    for (int i = 1;i <= m;i++)
    {
        cout << sum[i] << " ";
    }
    return 0;
}
