#include<bits/stdc++.h>
using namespace std;
const long long MX=2e5+10;
long long n,m,a[MX],tj,pw[30],aa=-1;
bool vs[25];
void dfs(int dep,long long now)
{
    if(dep>m)
    {
        aa=max(aa,now);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vs[i])
        {
            vs[i]=1;
            dfs(dep+1,now&a[i]);
            vs[i]=0;
        }
    }
    return;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    pw[0]=1;
    bool mk=0;
    for(int i=1;i<=22;i++)
    {
        pw[i]=pw[i-1]*2;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        bool lb=0;
        for(int i=1;i<=22;i++)
        {
            if(pw[i]==a[i]+1);
            {
                lb=1;
                break;
            }
        }
        if(!lb)
        {
            mk=1;
        }
        if(i==1)
        {
            tj=a[i];
        }
        else
        {
            tj=tj&a[i];
        }
    }
    if(m==1)
    {
        sort(a+1,a+n+1);
        cout<<a[n];
        return 0;
    }
    if(m==n)
    {
        cout<<tj;
        return 0;
    }
    if(m==2)
    {
        long long ans=-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    if(n<=20)
    {
        for(int i=1;i<=n;i++)
        {
            vs[i]=1;
            dfs(2,a[i]);
            vs[i]=0;
        }
        cout<<aa;
        return 0;
    }
    if(m==n-1)
    {
        long long pp=-1;
        for(int i=1;i<=n;i++)
        {
            bool bk=0;
            long long nn;
            for(int j=1;j<=n;j++)
            {
                if(j==i)
                {
                    continue;
                }
                if(bk==0)
                {
                    nn=a[j];
                    bk=1;
                    continue;
                }
                nn=nn&a[j];
            }
            pp=max(pp,nn);
        }
        cout<<pp;
        return 0;
    }
    if(mk==0)
    {
        long long as;
        sort(a+1,a+n+1);
        as=a[n];
        for(int i=2;i<=m;i++)
        {
            as=as&a[n-i+1];
        }
        cout<<as;
        return 0;
    }
    sort(a+1,a+n+1);
    long long ss=a[n];
    for(int i=2;i<=m;i++)
    {
        ss=ss&a[n-i+1];
    }
    cout<<ss;
    return 0;
}
