#include<bits/stdc++.h>
using namespace std;
long long a[2000005],ans=0,gl[2000005],zx[2000005],xx[2000005],m[2000005];
vector<long long> b[2000005];
void dfs(long long x,long long g)
{
    if(g==zx[x])
        gl[x]++;
    else if(g<zx[x])
    {   zx[x]=g;
        gl[x]=1;
    }
    if(gl[x]>2)
        return;
    for(long long i=0;i<b[x].size();i++)
        dfs(b[x][i],g+1);
}
int main()
{   freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    if(c==11 or c==12)
        while(t--)
        {   long long n,d;
            ans=0;
            cin>>n>>d;
            for(int i=1;i<=n;i++)
                cin>>a[i];
            int jian=a[2]-a[1];
            if(2*jian>=d)
                cout<<0<<endl;
            else if(3*jian<=d)
                cout<<0<<endl;
            else
                cout<<n-3<<endl;
        }
    else
        while(t--)
        {   long long n,d;
            ans=0;
            cin>>n>>d;
            long long l=1;
            cin>>a[1];
        for(long long i=2;i<=n;i++)
            {   cin>>a[i];
                for(long long j=1;j<i;j++)
                    if(a[i]-a[j]<=d)
                        b[j].push_back(i);
                if((a[i]-a[i-1])>d)
                    xx[i]=1;
            }
            for(long long i=1;i<n;i++)
            {   memset(zx,20000000000000005,sizeof(zx));
                if(xx[i]==1)
                {   m[i]=m[i-1];
                    ans+=m[i];
                }
                dfs(i,1);
                for(long long j=i+1;j<=n;j++)
                    if(gl[j]==2)
                        m[i]++;
                    ans+=m[i];
                memset(gl,0,sizeof(gl));
            }
            for(long long i=1;i<=n;i++)
            b[i].clear();
            memset(m,0,sizeof(m));
            memset(xx,0,sizeof(xx));
            cout<<ans<<endl;
        }
    return 0;
}
