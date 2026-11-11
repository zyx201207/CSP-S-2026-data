#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],a[500005][25],t[500005][25],vis[500005],ans=0,f[500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<=500003;i++) f[i]=0;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int x,y;
            cin>>x>>y;
            f[x]++;
            a[x][f[x]]=i;
            t[x][f[x]]=y;
        }
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        ans+=(w[l]+w[r]);
        cout<<ans+t[l][1]+t[r][1]<<'\n';
    }
    return 0;
}
