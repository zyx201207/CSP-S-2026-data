#include<iostream>
#include<cstdio>
using namespace std;
long long n,m,a[200005],ma=0;
void qqq(long long x,long long y,long long ans,int flag)
{
    if(x==0)
    {
        if(ma>ans)
        {
            return;
        }
        else
        {
            ma=ans;
            return;
        }
    }
    for(int j=y;j<=n-x+1;j++)
    {
        if(flag==1)
        {
            ans=qqq(m-1,j+1,a[j],0);
        }
        else
        {
            ans=qqq(m-1,j+1,ans&a[j],0);
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    qqq(m,1,0,1);
    cout<<ma;
    return 0;
}