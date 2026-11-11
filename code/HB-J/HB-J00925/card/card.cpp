#include <bits/stdc++.h>
using namespace std;
int n,m,a[300005],sum[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i];

    }
    for(int i = 1;i <= n;i++)
    {

        for(int j = i;j <= n;j++)
        {
            if(a[j]<a[j+1]&&j!=n)sum[a[j]]++;
            if(j==n)sum[a[j]]++;
        }
    }
    for(int i = 1;i <= m;i++)
    {

        cout<<sum[i];
    }
    return 0;
}
