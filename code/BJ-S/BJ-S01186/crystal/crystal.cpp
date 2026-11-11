#include <bits/stdc++.h>
using namespace std;
int num[500005];
int main()
{
    freopen ("crystal.in","r",stdin);
    freopen ("crystal.out","w",stdout);
    int n,m,a[500005];
    cin>>n>>m;
    int bigs[m];
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=m;i++)
    {
        int small=1000,id;
        for (int j=1;j<=n;j++)
        {
            if (a[j]<small)
            {
                small=a[j];
                id=j;
            }
        }
        a[id]++;
    }
    int big=0;
    for (int j=1;j<=n;j++)
    {
        num[a[j]]++;
    }
    for (int j=1;j<=500005;j++)
    {
        big=max(big,num[j]);
    }
    cout<<big;
    return 0;
}