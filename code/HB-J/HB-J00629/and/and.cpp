#include <bits/stdc++.h>
using namespace std;
long long n,m,sum,maxn=-8e10,vis[100050],a[100050];
void dfs(int step)
{
    if(step>n)
    {
        for(long long i=0;i<=n;i++)
        {
            if(vis[i]==0)
            {
                sum=a[i]&a[i+1];
            }
        }
        maxn=max(maxn,sum);
        sum=maxn;
        return;
    }
    for(long long i=0;i<=1;i++)
    {
        vis[step]=i;
        dfs(step+1);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(1);
    cout<<sum;
    return 0;
}
