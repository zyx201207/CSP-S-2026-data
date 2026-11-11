//GZ-S00117 贵阳市第十九中学 武钰轩 
#include<iostream>
using namespace std;
int mian()
{
    freopen("pow.in","r",stdin);
    freopen("pow.out","w",stdout);
    int c,t,n,d,a[10005],x=0,y=0;
    cin>>c>>t;
    for(int i=0;i<=t;i++)
    {
        cin>>n>>d;
        for(int j=0;j<=n;j++)
        {
            cin>>a[j];
            x+=a[j];
        }
        for(int j=0;j<=n;j++)
        {
            for(int z=j+1;z<=n;z++)
            {
                if(a[j]+a[z]==x/2&&a[j]+a[z]<=d)
                {
                    y++;
                }
            }
        }
        cout<<y<<endl;
    }
    return 0;
}
