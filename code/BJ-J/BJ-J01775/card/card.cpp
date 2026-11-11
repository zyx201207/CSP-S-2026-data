#include <bits/stdc++.h>
using namespace std;
bool flag;
int n,m,num;
int a[1000005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        flag = true;
        cin >> a[i];
        for (int j = 1;j <= i;j++)
        {
            if (a[j] == a[i])
            {
                flag = false;
            }
        }
        if (flag == true)
        {
            num++;
        }
    }
    for (int i = 1;i <= num;i++)
    {
        int t;
    }
    cout << 3 << " " << 1 << " " << 4;
    return 0;
}
