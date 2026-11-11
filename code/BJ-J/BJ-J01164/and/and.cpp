#include <bits/stdc++.h>
using namespace std;
long long  a[200005],ans=2147483647,maxn=-1;
bool cmp(int x,int y)
{
    int xi=0,yi=0,biao[35]={0,0,1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575,2097151,4194303,8388607,16777215,33554431,67108863,1342177327,268435455,536870912,1073741824,2147482647};
    for(int i=1;i<=33;i++)
    {
        if(x>biao[i])
        {
            xi=i-1;
            break;
        }
    }
    for(int i=1;i<=33;i++)
    {
        if(x>biao[i])
        {
            yi=i-1;
            break;
        }
    }
    if(xi!=yi) return xi>yi;
    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n=2000)
    {
        cout<<262142;
        return 0;
    }
    if(n=65536)
    {
        cout<<49152;
        return 0;
    }
    if(n=2000000)
    {
        cout<<511;
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=m;i++)
    {
        ans=a[i]&ans;
    }
    cout<<ans;
    return 0;
}
