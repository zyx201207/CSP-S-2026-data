#include <iostream>
using namespace std;
int ans[10000];
int a[10000], b[10000], c[10000];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    bool flag = true;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i - 1] > a[i])
        {
            flag = false;
        }
    }
    if(flag == true)
    {
        for(int i = 1; i <= n; i++)
        {
            int cnt = 1;
            c[a[i]] += 1;
            for(int j = i + 1; j <= n; j++)
            {
                if(a[j] != a[j - 1]) c[a[j]] += 1;
            }
        }
        for(int i  = 1; i <= m; i++)
        {
            cout << c[i] << " ";
        }
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int i = 1; i <= n; i++)
        {
            b[i] = 0;
            c[i] = 0;
        }
        for(int j = i; j <= n; j++)
        {
            if(b[a[j]] != 0)
            {
                for(int k = b[a[j]]; k < j; k++)
                {
                    c[k] = 1;
                    b[a[k]] = 0;
                }
            }
            b[a[j]] = j;
        }
        for(int j = i; j <= n; j++)
        {
            if(c[j] != 1)
            {
                ans[a[j]]++;   
            }
        }
    }
    for(int i = 1; i <= m; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}