#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005],sum,num,num1;
int g(int n,int m)
{
    for(int i=n;i<=m;i++)
    {
        for(int j=i;j<=m;j++)
        {
            if(a[j]-a[i]<d)
            {
                sum++;
            }
        }
    }
    return sum;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j];
        }
        for(int j=1;j<=n;j++)
        {
            for(int k=j;k<=n;k++)
            {
                cout<<g(j,k);
            }
        }
    }
    return 0;
}
