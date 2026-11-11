#include<bits/stdc++.h>
using namespace std;
#define gbb(u,i) ((u>>(i-1))-(u>>i<<1))
int n,m,a[1000005];
bool ispass[65];
int b[65];
int ans=0;
bool cmp(int x,int y)
{
    if(gbb(x,32)!=gbb(y,32))return gbb(x,32)<gbb(y,32);
    for(int i=31;i>=1;i--)
    {
        if(ispass[i])
        {
            x>>1;y>>1;
            continue;
        }
        if(gbb(x,i)!=gbb(y,i))return gbb(x,i)>gbb(y,i);
        x>>1;y>>1;
    }
    return gbb(x,0)>gbb(y,0);
}
int main()
{
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int x=a[i];
        for(int i=31;i>=1;i--)
        {
            b[gbb(x,i)]++;
            x>>1;
        }
    }
    for(int i=1;i<=31;i++)
    {
        if(b[i]<m)ispass[i]=1;
    }
    sort(a+1,a+n+1,cmp);
    /*
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<' ';
    }
    */
    int ans=0x7fffffff;
    for(int i=1;i<=m;i++)
    {
        ans=ans&a[i];
    }
    cout<<ans;
	return 0;
}