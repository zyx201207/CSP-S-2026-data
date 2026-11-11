#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, M = 1e5 + 5;

int n, m, l, a[N],  c[M];
string  s;

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m; // 4, 3
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i]; // 1 2 1 3
    }

    int n2 = n;//n2 = n = 4
    while(n2--)
    {
        l++;//l = 1
        for(int i = l; i <= n; i++)//i = 1, i <= 4
        {
            bool b = true;
            int p = 0;
            if(i > l)
            {
                for(int j= l; j <= i; j++)
                {
                    if(a[i] == a[j])
                    {
                        b = false;
                        p = i;
                    }
                }
                if(b)
                {
                    s += a[i];
                }
                else
                {
                    for(int k = p + 1; k <= s.size(); k++)
                    {
                        s[k] = 0;
                    }
                }
            }
            else
            {
                c[a[i]]++;
                //cout << s << ' ';
            }
        }
    }
    for(int i = 1; i <= m; i++) cout << c[i] << ' ';
    return 0;
}
