#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,mn;
bool b[2100000];
vector <long long> vt[2100000];
void check(long long u)
{
    long long v,ls=vt[u].size();
    b[u]=false;
    for(long long i=0;i<ls;i++)
    {
        v=vt[u][i];
        if(b[v]==true)
        {
            check(v);
        }
    }
    return;
}
long long bdfconta(long long u,long long fa)
{
    // cout<<u<<" "<<fa<<"\n";
    long long v,ls=vt[u].size(),mz=1e18;
    if(b[u]==true)
    {
        return 0;
    }
    for(long long i=0;i<ls;i++)
    {
        v=vt[u][i];
        if(v==fa)
        {
            continue;
        }
        mz=min(mz,bdfconta(v,u));
    }
    return mz+1;
}
void bddfs(long long z,long long s)
{
    long long mx=0;
    if(z==n+1)
    {
        if(s!=k)
        {
            return;
        }
        s=0;
        for(long long i=1;i<=n;i++)
        {
            mx=max(mx,bdfconta(i,0));
        }
        for(long long i=1;i<=n;i++)
        {
            if(b[i]==true)
            {
                check(i);
                s++;
            }
        }
        if(s!=2)
        {
            return;
        }
        mn=min(mn,mx);
        return;
    }
    bddfs(z+1,s);
    b[z]=true;
    bddfs(z+1,s+1);
    b[z]=false;
    return;
}
void workrun()
{
    mn=1e18;
    long long u,v;
    cin>>n>>k;
    for(long long i=1;i<=n;i++)
    {
        b[i]=false;
        vt[i].clear();
    }
    for(long long i=1;i<n;i++)
    {
        cin>>u>>v;
        vt[u].push_back(v);
        vt[v].push_back(u);
    }
    bddfs(1,0);
    cout<<mn<<"\n";
    return;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    for(long long i=1;i<=t;i++)
    {
        workrun();
    }
    return 0;
}
