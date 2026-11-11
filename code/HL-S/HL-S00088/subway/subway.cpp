#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,k,x,y;
int w[N],a[505][505],t[505][505];
int dist[N];
void dij(int s)
{
    for(int i=1;i<=n;i++) dist[i]=t[s][i];
    int u=0;
    for(int i=1;i<=n;i++)
    {
        if(dist[u]<dist[i]+t[u][i])
            dist[u]=dist[i]+t[u][i];
        u++;
    }
    return;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    while(q--)
    {
        for(int i=1;i<=m;i++) cin>>w[i];
        for(int i=1;i<=q;i++)
        {
            cin>>k;
            for(int i=1;i<=k;i++){
                for(int j=1;j<=k;j++)
                {
                    cin>>a[i][j]>>t[i][j];
                }
            }
        }
        cin>>x>>y;
        dij(1);
        cout<<dist[n]<<endl;
    }


    return 0;
}


