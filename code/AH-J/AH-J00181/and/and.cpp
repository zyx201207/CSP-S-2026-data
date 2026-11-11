#include<bits/stdc++.h>
using namespace std;
int n,m,v[200005];
long long a[200005],maxn,mn1;
void dfs(int step,long long num)
{
    if(step>m)
    {
        maxn=max(num,maxn);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!v[i])
        {
            v[i]=1;
            dfs(step+1,num&a[i]);
            v[i]=0;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mn1=max(mn1,a[i]);
        if(m==1)
        {
            maxn=max(maxn,a[i]);
        }
        else if(m==n)
        {
            if(i==1)
            {
                maxn=a[i];
            }
            else
            {
                maxn=maxn&a[i];
            }
        }
    }
    if(m==n||m==1)
    {
        cout<<maxn;
        return 0;
    }
    if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout<<maxn;
        return 0;
    }
    if(mn1<4)
    {
        cout<<3;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        v[i]=1;
        dfs(2,a[i]);
        v[i]=0;
    }
    cout<<maxn;
    return 0;
}
