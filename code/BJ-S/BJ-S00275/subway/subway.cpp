#include<bits/stdc++.h>
using namespace std;
int Cca,n,m,d,q,a[500001],s[501][500001],ans=1e9,f[500001];
void wrk(int t,int nw,int fnsh)
{
    if(nw==fnsh)
    {
        ans=min(ans,t);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i][nw])
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i][j]&&!f[j])
                {
                    f[j]=1;
                    wrk(t+s[i][nw]+s[i][j],j,fnsh);
                    f[j]=0;
                }
            }
        }
    }
    return;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>Cca>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int b,t;
            cin>>b>>t;
            s[i][b]=t;
        }
    }
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        if(u==v)
        {
            cout<<"0"<<'\n';
            continue;
        }
        memset(f,0,sizeof(f));
        f[u]=1;
        wrk(a[u]+a[v],u,v);
        cout<<ans<<'\n';
    }
    return 0;
}
