#include<iostream>
using namespace std;
int cc,n,m,_,q,a[500005],b[500005],c[500005],c2[500005],k,k2,d[1005][1005],x,y;
void n1()
{
    cin>>k;
    for(int i=1;i<=k;i++)
    {
        cin>>b[i];
        cin>>c[b[i]];
    }
    while(q--)
    {
        cin>>x>>y;
        cout<<a[x]+c[x]+c[y]+a[y]<<"\n";
    }
    exit(0);
}
void n2()//8pts
{
    cin>>k;
    int t;
    for(int i=1;i<=k;i++)
    {
        cin>>t;
        cin>>c[t];
    }
    cin>>k2;
    int mn=2e9,s=0;
    for(int i=1;i<=k2;i++)
    {
        cin>>t>>c2[t];
        if(c[t])
        {
            mn=min(mn,c[t]+c2[t]);
        }
    }
    while(q--)
    {
        cin>>x>>y;
        s=2e9;
        if(c[x]&&c[y])
        {
            s=min(s,a[x]+c[x]+c[y]+a[y]);
        }
        else if(c2[x]&&c2[y])
        {
            s=min(s,a[x]+c2[x]+c2[y]+a[y]);
        }
        else if(c[x]&&c2[y])
        {
            s=min(s,a[x]+c[x]+mn+c2[y]+a[y]);
        }
        else
        {
            s=min(s,a[x]+c2[x]+c[y]+a[y]);
        }
        cout<<s<<"\n";
    }
    exit(0);
}
int main()//52pts
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>cc>>n>>m>>_>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        n1();
    }
    if(n==2)
    {
        n2();
    }
    for(int i=1;i<=m;i++)//44pts
    {
        for(int j=1;j<=m;j++)
        {
            d[i][j]=2e9;
        }
    }
    while(n--)
    {
        cin>>k;
        for(int i=1;i<=k;i++)
        {
            cin>>b[i];
            cin>>c[b[i]];
        }
        for(int i=1;i<k;i++)
        {
            for(int j=i+1;j<=k;j++)
            {
                d[b[i]][b[j]]=min(d[b[i]][b[j]],c[b[i]]+c[b[j]]);
                d[b[j]][b[i]]=d[b[i]][b[j]];
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(d[i][j]==2e9)
            {
                continue;
            }
            for(int k=1;k<=m;k++)
            {
                if(d[i][k]==2e9)
                {
                    continue;
                }
                d[j][k]=min(d[j][k],d[i][j]+d[i][k]);
            }
        }
    }
    while(q--)
    {
        cin>>x>>y;
        cout<<a[x]+a[y]+d[x][y]<<"\n";
    }
    return 0;
}
