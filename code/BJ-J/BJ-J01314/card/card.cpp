#include <bits/stdc++.h>
using namespace std;
int a[500005];
int num[300005];
int ans[300005];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    if(n <= 5)
    {
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i];
        }
        for(int i = 1;i <= n;i++)
        {
            memset(num,0,sizeof(num));
            for(int j = i;j <= n;j++)
            {
                bool flag = false;
                int temp = 0;
                for(int k = 1;k <= n;k++)
                {
                    if(a[j] == num[k]) flag = true,temp = k;
                }
                if(!flag) num[j] = a[j];
                else
                {
                    for(int k = temp;k <= n;k++) num[k] = 0;
                    num[j] = a[j];
                }
            }
            for(int j = 1;j <= n;j++)
            {
                ans[num[j]]++;
            }
        }
        for(int i = 1;i <= m;i++)
        {
            cout << ans[i] << " ";
        }
    }
    else
    {
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i];
            num[a[i]]++;
        }
        for(int i = 1;i <= m;i++)
        {
            ans[i] = ans[i - 1] + num[i];
            cout << ans[i] << " ";
        }
    }
    return 0;
}
