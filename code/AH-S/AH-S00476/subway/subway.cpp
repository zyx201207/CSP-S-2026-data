#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    unsigned long long z,n,m,d,q,a[500005],b[505][500005],c[505],d,e,ans=0;
    long long f,g,x,y;
    cin>>z>>n>>m>>d>>q;
    for(unsigned long long i=1;i<=m;i++)
    cin>>a[i];
    for(unsigned long long i=1;i<=n;i++)
    {
        cin>>c[i];
        for(int j=1;j<=c[i]*2;j++)
        cin>>b[i][j];
    }
    for(unsigned long long i=1;i<=q;i++)
    {
        ans=0;
        cin>>d>>e;
        ans+=a[d];
        ans+=a[e];
        for(unsigned long long j=1;j<=n;j++)
        {
            for(unsigned long long k=1;k<=c[j]*2;k+=2)
            {
                if(b[j][k]==d)
                {
                    d=0;
                    f=j;
                    x=k;
                }
                if(b[j][k]==e)
                {
                    g=j;
                    e=0;
                    y=k;
                }
            }
        }
        if(f==g)
        {
            ans=ans+b[f][x]+b[g][y];
        }
        cout<<ans<<endl;
}
