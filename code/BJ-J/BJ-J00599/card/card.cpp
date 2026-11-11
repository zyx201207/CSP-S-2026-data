#include <bits/stdc++.h>
using namespace std;
long long a[10000000],b[100000000],c[10000000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<=i;j++)
        {
            if (a[i]==b[j])
            {
                for (int k=j+1;k<i;k++)
                {
                    b[k]=0;
                }
            }
            else
                b[i]=a[i];
        }

        for (int j=0;j<n;j++)
        {
            if (b[j]!=0)
            {
                c[b[j]]++;
            }
        }
    }
    for (int i=0;i<n;i++)
    {
        cout << c[i] << " ";
    }
    return 0;
}
