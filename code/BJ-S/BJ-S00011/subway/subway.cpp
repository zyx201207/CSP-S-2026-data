#include<bits/stdc++.h>
using namespace std;
const int N=505,K=5e5+5;
int c,n,m,d,q,ans;
int w[N],k[N],a[N][K/2],t[N][K/2],h[N][K/2];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
            h[i][a[i][j]]=1;
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        ans=w[x]+w[y];
        for(int i=1;i<=n;i++)
            if(h[i][x]==1&&h[i][y]==1) ans+=t[i][x]+t[i][y];
            cout<<ans<<"\n";
    }
    return 0;
}