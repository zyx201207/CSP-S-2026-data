#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,d,q,t[500005],k[505],c[505],ans,cnt[55][305];
bool vis[305];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>n>>n>>m>>d>>q;
    if(n==1)
    {
        for(int i=1;i<=m;i++) cin>>t[i];
        cin>>k[1];
        for(int i=1;i<=k[1];i++)
        {
            int a,b;
            cin>>a>>b;
            cnt[1][a]=b;
        }
        for(int i=1;i<=q;i++)
        {
            int s,tt;
            cin>>s>>tt;
            cout<<t[s]+t[tt]+cnt[1][s]+cnt[1][tt]<<"\n";
        }
        return 0;
    }
    if(n==2)
    {
        for(int i=1;i<=m;i++) cin>>t[i];
        cin>>k[1];
        for(int i=1;i<=k[1];i++)
        {
            int a,b;
            cin>>a>>b;
            cnt[1][a]=b;
        }
        cin>>k[2];
        for(int i=1;i<=k[2];i++)
        {
            int a,b;
            cin>>a>>b;
            cnt[2][a]=b;
        }
        for(int i=1;i<=q;i++)
        {
            int s,tt;
            cin>>s>>tt;
            int ans=INT_MAX;
            if(cnt[1][s]&&cnt[1][t]) ans=min(ans,cnt[1][s]+cnt[1][t]);
            if(cnt[2][s]&&cnt[2][t]) ans=min(ans,cnt[2][s]+cnt[2][t]);
            cout<<ans+t[s]+t[tt]<<"\n";
        }
        return 0;
    }
    return 0;
}