#include <bits/stdc++.h>
using namespace std;

int n,m;
long long a[500005];


int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i ++)
    {
        cin >> a[i];
    }
    sort(a +1,a + n +1);
    for (int i = n;i >= 1;i --)
    {
        int sum  = 0;
        bool flag = true;

        for (int j = 1;j <= n;j ++)
        {
            sum += (a[i] - a[j]);
            if (sum > m)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << i;
            break;
        }
    }
    fclose(stdin);
    fclose(stdout);


    return 0;
}
