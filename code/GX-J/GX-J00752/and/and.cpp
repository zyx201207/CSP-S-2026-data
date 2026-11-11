#include<bits/stdc++.h>
using namespace std;
int aa[200005],a[35][200005],n,m,sum=0;
int c(int d)
{
    int e=2;
    for(int i=1;i<d;i++)
        e=e*2;
    return e;
}
void f(int z,int nn,int sum)
{
    int u;
    for(int u=z;u<30;u++)
    {
        int ans=0;
        for(int j=1;j<=nn;j++)
            ans+=a[u][j];
        if(ans>=m)
        {
            sum+=c(u);
            z=u;
            break;
        }
    }
    if(u!=29)
        f(z,nn,sum);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n+1;i++)
    {
        cin>>aa[i];
    }
    sort(aa+1,aa+1+n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=30;j++)
        {
            if(aa[i]%2==1)
                a[30-j][i]=1;
            aa[i]=aa[i]/2;
        }
    }
    f(0,n,sum);
    cout<<sum;
    return 0;
}
