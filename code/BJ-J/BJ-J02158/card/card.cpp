#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500010];
ll vis[300010];
ll ans[500010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        ll k=0;
        for(int j=1;j<=n;j++)
        {
            if(vis[a[i]]==0)
            {
                k++;
                vis[a[i]]=k;
            }
            else
            {
                for(int q=1;q<=300010;q++) if(vis[q]>=k) vis[q]=0;
            }
        }
        for(int j=1;j<=n;j++)
        {
            for(int q=1;q<=300010;q++)
            {
                if(vis[q]!=0) ans[j]++;
            }
        }
    }
    for(int j=1;j<=n;j++)
    {
        cout<<ans[j];
    }
    return 0;
}
