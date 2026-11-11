#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int zd=0;
    for(int i=1;i<=n;i++)
    {
        int sum=0;
        for(int j=1;j<i;j++)
        {
            sum+=a[i]-a[j];
        }
        if(sum<=m && i>zd)
        {
            zd=i;
        }
    }
    cout<<zd;
    return 0;
}
