#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[200005],b[200005];
bool t[200005];
void dfs(int dep,int x)
{
    b[dep]=x;
    if(dep==m)
    {
        long long res=b[1];
        for(long long i=2;i<=m;i=i+1)
        {
            res=res&b[i];
        }
        ans=max(res,ans);
        return;
    }
    for(int i=1;i<=n;i=i+1)
    {
        if(!t[i])
        {
            t[i]=1;
            dfs(dep+1,a[i]);
            t[i]=0;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i=i+1)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i=i+1)
    {
        if(!t[i])
        {
            t[i]=1;
            dfs(1,a[i]);
            t[i]=0;
        }
    }
    cout<<ans;
    return 0;
}