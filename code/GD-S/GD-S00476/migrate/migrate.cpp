#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,f[1100][1100],s[1100][1100],x,y,z,a[2100000];
void workrunA()
{
    cin>>n>>d;
    if(n==1)
    {
        cout<<"0\n";
        return;
    }
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    z=a[2]-a[1];
    if(z>d)
    {
        cout<<"0\n";
        return;
    }
    z=d/z;
    z=2*z-1;
    if(n<z || z==1)
    {
        cout<<"0\n";
        return;
    }
    cout<<n-z<<"\n";
    return;
}
void workrunB()
{
    long long dn=0;
    cin>>n>>d;
    if(n==1)
    {
        cout<<"0\n";
        return;
    }
    z=0;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++)
    {
        z=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
        if(z==n || z==i+1)
        {
            continue;
        }
        x=a[z]-a[z-2];
        x=d-x;
        y=upper_bound(a+1,a+n+1,a[z]+x)-a;
        if(y>n)
        {
            continue;
        }
        dn+=n-y+1;
    }
    cout<<dn<<"\n";
    return;
}
void workrun()
{
    cin>>n>>d;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++)
    {
        for(long long j=0;j<=n;j++)
        {
            f[i][j]=1e18;
            s[i][j]=0;
        }
    }
    z=0;
    for(long long i=1;i<=n;i++)
    {
        f[i][i]=0;
        s[i][i]=1;
        for(long long j=i+1;j<=n;j++)
        {
            for(long long k=i;k<j;k++)
            {
                if(a[j]-a[k]<=d)
                {
                    if(f[i][k]+1<f[i][j])
                    {
                        f[i][j]=f[i][k]+1;
                        s[i][j]=s[i][k];
                    }else if(f[i][k]+1==f[i][j])
                    {
                        s[i][j]+=s[i][k];
                    }
                }
            }
            if(s[i][j]==2)
            {
                z++;
            }
        }
    }
    cout<<z<<"\n";
    return;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    for(long long i=1;i<=t;i++)
    {
        if(c==11 || c==12)
        {
            workrunA();
            continue;
        }
        if(c==13 || c==14)
        {
            workrunB();
            continue;
        }
        workrun();
    }
    return 0;
}
