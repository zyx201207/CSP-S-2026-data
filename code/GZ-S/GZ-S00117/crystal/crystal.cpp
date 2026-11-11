//GZ-S00117 贵阳市第十九中学 武钰轩 
#include<iostream>
using namespace std;
int mian()
{
    freopen("pow.in","r",stdin);
    freopen("pow.out","w",stdout); 
   	int n,m,a[10005];
    cin>>n>>m;
    for(int i=0;i<=n;i++)
    {
        cin>>a[i];
    }
    int q=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(m!=0&&a[i]+a[j]<=m)
            {
                m-=(a[i]-a[j]);
                q++;
            }
        }
    }
    cout<<q;
    return 0;
}
