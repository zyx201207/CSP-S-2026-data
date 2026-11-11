#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000005];
bool v[2000005];
int n,d,c,t;
int aans=5e18,cnt=0;
void dfs(int x,int depth,int e)
{
    if(x>e) return ;
    else if(x==e)
    {
        if(depth<aans)
        {
            aans=depth;
            cnt=1;
            return ;
        }
        else if(depth==aans)
        {
            cnt++;
            return ;
        }
    }
    for(int i=x;i<=e;i++)
    {
        if(!v[i]&&a[x]+d>=a[i])
        {
            v[i]=1;
            dfs(i,depth+1,e);
            v[i]=0;
        }
    }
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        int ans=0;
        cin>>n>>d;
        fill(v+1,v+n+1,0);
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                v[j]=1;
                dfs(j,0,i);
                fill(v+1,v+n+1,0);
            }
            if(cnt==2)
                ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
