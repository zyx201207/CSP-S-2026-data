#include <bits/stdc++.h>
using namespace std;
int a[100000];
int ma__(int ma,int x,int y,int z)
{
    if (z==0)
        return 0;
    for (int j=x;j<=y;j++)
    {
        ma=max(ma,a[x]|a[j]);
    }
    return max(ma__(ma,x+1,y,z-1),ma);
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    int ma=0;
    if (m==1)
    {
        for (int i=1;i<=n;i++)
            ma=max(a[i],ma);
        cout<<ma;
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        ma=max(ma__(0,i,n,m),ma);
    }
    cout<<ma;
    return 0;
}
