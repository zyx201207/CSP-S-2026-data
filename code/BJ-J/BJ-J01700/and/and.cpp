#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn =0;
bool f[200005];
void dfs(int step,int cnt)
{
    if(step==m)
    {
        maxn = max(maxn,cnt);
        return ;
    }
    for(int i = 1;i<=n;i++)
    {
        if(!f[i])
        {
            f[i]=true;
            dfs(step+1,(cnt&a[i]));
            f[i]=false;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++)
    {
        f[i]=true;
        dfs(1,a[i]);
        f[i]=false;
    }
    cout<<maxn;
    return 0;
}