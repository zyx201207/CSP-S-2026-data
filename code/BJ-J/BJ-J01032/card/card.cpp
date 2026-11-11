#include<bits/stdc++.h>
using namespace std;
int a[500005], ans[300005];
string s;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        s = "";
        for(int j = i; j <= n; j++)
        {
            char c = a[j] + '0';
            int l = s.size();
            s += c;
            int pos = -1;
            for(int k = 0; k < l; k++)
            {
                if(s[k] == c)
                {
                    pos = k;
                    break;
                }
            }
            if(pos == -1)
                continue;
            string s1;
            for(int k = 0; k < pos; k++)
                s1 += s[k];
            s1 += c;
            s = s1;
        }
        for(int j = 0; j < s.size(); j++)
            ans[s[j] - '0']++;
    }
    for(int i = 1; i <= m; i++)
        cout << ans[i] << " ";
    return 0;
}
