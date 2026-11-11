#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N];
int n,m;
int fina=-1;
void dfs(int pos,int cnt,int ans)
{
    if(cnt==m)
    {
        fina=max(ans,fina);
       // cout<<ans<<" ";
       return ;
    }
    if(pos==n)
    {

        return ;
    }
    for(int i=pos+1;i<=n;i++)
    {
            dfs(i,cnt+1,ans&a[i]);
    }

}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        int maxx=-1;
        for(int i=1;i<=n;i++)
        {
            maxx=max(maxx,a[i]);
        }
        cout<<maxx;
        return 0;
    }
    if(m==n)
    {
        int ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {

        dfs(i,1,a[i]);
    }
    cout<<fina;
    return 0;
}
