//GZ-S00117 贵阳市第十九中学 武钰轩 
#include<iostream>
using namespace std;
int mian()
{
    freopen("pow.in","r",stdin);
    freopen("pow.out","w",stdout);
    int c,t,n,k,a[10005],x=1000;
    cin>>c>>t;
    for(int i=0;i<=t;i++)
    {
        cin>>n>>k;
        for(int j;j<=n+k;j++)
        {
            cin>>a[j];
        }
        for(int j;j<=n+k;j++)
        {
            if(a[j]<x&&a[j]<3)
            {
                x=a[j];
            }
        }
        cout<<x<<endl;
    }
    return 0;
}
