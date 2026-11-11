#include<bits/stdc++.h>
using namespace std;
long long a[10000000],num;
int main()
{
    int n,m;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    if (n==m)
    {
        num=a[0];
        for (int i=1;i<n;i++)
        {
            num=num&a[i];
        }
        cout << num;
    }
    else if (m==1)
    {
        sort(a,a+n);
        cout << a[n-1];
    }
    else if (m==2)
    {
        for (int i=0;i<n-1;i++)
        {
            for (int j=i+1;j<n;j++)
            {
                if (a[i]&a[j]>num)
                {
                    num=a[i]&a[j];
                }
            }
        }
        cout << num;
    }
    else if (m==3)
    {
        for (int i=0;i<n-2;i++)
        {
            for (int j=i+1;j<n-1;j++)
            {
                for (int k=j+1;k<n;k++)
                {
                    if ((a[i]&a[j])&a[k]>num)
                    {
                        num=(a[i]&a[j])&a[k];
                    }
                }

            }
        }
        cout << num;
    }
    else if (m==4)
    {
        for (int i=0;i<n-3;i++)
        {
            for (int j=i+1;j<n-2;j++)
            {
                for (int k=j+1;k<n-1;k++)
                {
                    for (int x=k+1;x<n;x++)
                    {
                        if ((a[i]&a[j])&a[k]&a[x]>num)
                        {
                            num=(a[i]&a[j])&a[k]&a[x];
                        }
                    }

                }

            }
        }
        cout << num;
    }
    return 0;
}
