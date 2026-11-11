#include <iostream>
using namespace std;
int N=10e18+10;
int main()
{
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
int n,m,a[N],b[N];
cin>>n>>m;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
}
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n-1;i++)
    {
        if(a[j]<a[j+1])
        {
        swap(a[j],a[j+1]);
        }
    }
}
for(int i=1;i<=n;i++)
{
b[i]=a[i]-a[i+1];
}
int x=-1;
int c=0;
int cnt=0;
for(int i=1;i<=n;i++)
{
    for(int j=i;j<=n-1;i++)
    {
        if(c+a[j]<=m)
        {
            c+=a[j];
            cnt++;
        }
        else
        {
        x=max(x,cnt);
        cnt=0;
        c=0;
        continue;
        }
    }
}
cout<<x;
return 0;
}
