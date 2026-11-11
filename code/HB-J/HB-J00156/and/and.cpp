#include <bits/stdc++.h>
using namespace std;

long long n,m,k[200001][32],p[30];


void init()
{
    for(long long i=1;i<=30;i++)
    {
        p[i]=2*p[i-1];
    }
}

void totwo(long long a,long long i)
{
    long long x=0,s[32];
    for(long long i=1;i<=32;i++) s[i]=0;
    while(a>0)
    {
        x++;
        s[x]=a%2;
        a/=2;
    }
    for(long long j=1;j<=31;j++)
    {
        k[i][j]=s[32-j];
    }
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    p[0]=1;
    init();
    cin>>n>>m;
    long long a[200001];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int z[200001];
    for(int i=1;i<=n;i++)
    {
        z[i]=a[n-i+1];
    }
    for(int i=1;i<=n;i++)
    {
        totwo(z[i],i);
    }
    long long be=1,en=n,ans=0;
    for(int i=1;i<=31;i++)
    {
        int hm1=0;
        for(int j=be;j<=en;j++)
        {
            if(k[j][i]==1) hm1++;
        }
        if(hm1>=m)
        {
            for(int t=1;t<=n;t++)
            {
                if(k[t][i]==1)
                {
                    be=t;
                    break;
                }
            }
            en=be+hm1-1;
            ans+=p[31-i];
        }
    }
    cout<<ans;
    return 0;
}
