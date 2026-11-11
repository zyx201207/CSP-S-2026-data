//GZ-S00084,罗子淇,贵阳市南明区第二实验中学；
#include<iostream>
using name space std;
int main()
{
    int n,m,sum=0,a[10005];
    freopen("crytal.in","r",stdin)
    freopen("crytal.out","w",stdout)
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        if(n+m>i)
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
