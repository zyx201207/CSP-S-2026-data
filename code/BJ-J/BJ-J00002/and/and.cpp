#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m,mark[200005],maxx=-1;
void dfs(int cur,int ans)
{
    if(cur==m)
    {
        if(ans>maxx)
        {
            maxx=ans;
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!mark[i])
        {
            mark[i]=1;
            dfs(cur+1,(ans&a[i]));
            mark[i]=0;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        dfs(0,a[i]);
    }
    cout<<maxx;
    return 0;
}
