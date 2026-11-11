include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[maxn];
long long ans=0;
long long sum=0;
bool vis[maxn];
void dfs(int x)
{
    vis[x]=1;

    if(x==m)
    {

        maxsum=max(maxsum,sum);
        return;
    }
    for(int i=1;i<=n;i++)
    {

        if(!vis[i])
        {

            dfs(x+1);
            vis[i]=0;
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
    int k=n-m+1;
    if(n<=20)
    {
        memset(vis,0,sizeof,vis);
        long long maxsum=dfs(0);
        ans=max(ans,maxsum_);
    }
    cout<<ans;

    return 0;
}
