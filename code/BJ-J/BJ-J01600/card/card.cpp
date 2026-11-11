#include<bits/stdc++.h>
using namespace std;
long long ans[200005],a[200005];
bool vis[200005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,mx=LLONG_MIN;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mx=max(a[i],mx);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            vis[j]=false;
        }
        for(int j=i;j<=n;j++)
        {
            if(!vis[a[j]])
            {
                vis[a[j]]=true;
            }
            else{
            for(int k=1;k<=mx;k++)
            {
                vis[k]=false;
            }
                vis[a[j]]=true;
            }
        }
        for(int j=1;j<=mx;j++)
        {
            if(vis[j])
            {
                ans[j]++;
            }
        }
    }
    for(int i=1;i<=mx;i++)
    {
        cout<<ans[i]<<" ";
    }
}
