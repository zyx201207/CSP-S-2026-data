#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int b[200005],ans=-1,x;
void dfs(int step)
{
    if(step>m)
    {
        x=b[1];
        for(int j=2;j<=m;j++)
        {
            
            x=x&b[j];
        }

        ans=max(ans,x);
        
        return;
    }
    for(int i=step+1;i<=n;i++)
    {
        b[step]=a[i];
        dfs(step+1);
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
    dfs(1);
    cout<<ans;
    return 0;
}
