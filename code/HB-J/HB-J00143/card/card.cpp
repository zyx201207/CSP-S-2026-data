#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a[200005];
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++)
    {
        int c = 0;
        for(int j = 1; j <= n; j++)
        {
            if(i == a[n])
            {
                c = n;
            }
            else if(a[j] == i)
            {
                c++;
            }
        }
        cout << c << " ";
    }
    return 0;
}
