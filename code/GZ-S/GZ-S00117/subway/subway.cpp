//GZ-S00117 贵阳市第十九中学 武钰轩 
#include<iostream>
using namespace std;
int mian()
{
    freopen("pow.in","r",stdin);
    freopen("pow.out","w",stdout);
    int n,m,x,y,s,a[10005],b[10005];
    cin>>n>>m>>x>>y>>s;
    for(int i=0;i<=m;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<=m;i++)
    {
        cin>>b[i];
    }
    for(int i=0;i<=s;i++)
	{
        cout<<a[i]+b[i]<<endl;
    }
    return 0;
}
