#include <bits/stdc++.h>
using namespace std;
const int N=2e4+5;
int c,n,m,d,q;
int w[N];
//vector<int>Q[N];
vector<int>P[N];
vector<int>G[N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>c>>n>>m>>d>>q;
   for(int i=1;i<=m;i++) cin>>w[i];
    for(int j=1;j<=n;j++)
    {
        int k,u,v;
        cin>>k;
        for(int i=1;i<=k;i++)
        {
           cin>>u>>v;
            P[u].push_back(j);
            G[u].push_back(v);
        }
    }

    while(q--)
    {
      // cout<<"8";
        int x,y,sum=0;
        cin>>x>>y;
        sum+=w[x];
        sum+=w[y];
        for(int xx=0;xx<=P[x].size();xx++)
            for(int yy=0;yy<=P[x].size();yy++)
        {
            if(P[x][xx]==P[y][yy]){   sum+=G[x][xx];sum+=G[y][yy];break;}
        }

        cout<<sum<<'\n';
    }
    return 0;
}
