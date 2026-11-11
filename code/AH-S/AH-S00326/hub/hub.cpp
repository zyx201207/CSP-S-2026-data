#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int g[N][N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    int big1=0,big2=0,ans=0;
    cin>>c>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        memset(g,0x3f,sizeof g);
        for(int i=1;i<=n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u][v]=1;
            g[v][u]=1;
        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    g[i][j]=min(g[i][j],g[i][k]+g[j][k]);
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                if(g[i][j]>=big1) ans=big2,big2=big1,big1=g[i][j];
                else if(g[i][j]<big1&&g[i][j]>=big2) ans=big2,big2=g[i][j];
                else if(g[i][j]<big2&&g[i][j]>=ans) ans=g[i][j];
            }
        cout<<ans<<"\n";
    }
    //Oct31==Dec25?
    return 0;
}