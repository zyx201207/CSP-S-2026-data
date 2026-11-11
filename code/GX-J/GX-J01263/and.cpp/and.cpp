#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,m1=0,a[100005],num=0;
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    if(m==2)
    {
        for (int i = 1;i <= n;i++)
        {
            for (int j = i+1;j <= n;j++)
            {
                if (a[i] & a[j] > num)
                {
                    num = a[i] & a[j];
                }
            }
        }
    }
    if(m==3)
    {
        for (int i = 1;i <= n;i++)
        {
            for (int j = i+1;j <= n;j++)
            {
                if (a[i] & a[j] & a[j+1] > num)
                {
                    num = a[i] & a[j];
                }
            }
        }
    }
    cout << num;
    return 0;
}
