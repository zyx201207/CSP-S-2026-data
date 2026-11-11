#include <iostream>
using namespace std;

int a[200010];
int t[7010][7010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >>n >>m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int cur = 0;
        for (int j = i; j <= n; j++)
        {
            bool flag = false;
            for (int k = i; k <= j - 1; k++)
            {
                if (a[j] == a[k])
                {
                    flag = true;
                    for (int s = i; s <= j - 1; s++)
                    {
                        t[i][s] = 0;
                    }
                    cur =0;
                    break;
                }
            }
            t[i][++cur] = a[j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int cnt = 0;
        for (int j= 1; j<= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (t[j][k] == i)
                {
                    cnt++;
                    break;
                }
            }
        }
        cout << cnt << " ";
    }
    return 0;
}
