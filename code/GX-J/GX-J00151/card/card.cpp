#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[n + 5],num[m + 5] = {0};
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++)
    {
        stack<int> b,c;
        for (int j = i;j <= n;j++)
        {
            if (!b.empty()) b.push(a[j]);
            else
            {
                while (!b.empty())
                {

                    c.push(b.top());
                    b.pop();
                    if (b.top() == a[j])
                    {
                        while (c.empty()) c.pop();
                        break;
                    }
                }
                while (!c.empty())
                {

                    b.push(c.top());
                    c.pop();
                }
            }
        }
        while (!b.empty())
        {
            num[b.top()]++;
            b.pop();
        }
    }
    for (int i = 1;i <= m;i++) printf("%d ",num[i]);
    return 0;
}
