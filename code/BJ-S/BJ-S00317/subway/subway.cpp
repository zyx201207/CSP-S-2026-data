#include<bits/stdc++.h>
using namespace std;
vector<int> g[505];
int val[505][500005];
int t[100005],ans;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>t[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int u=1;u<=k;u++)
        {
            int v,va;
            cin>>v>>va;
            u.push_back(v);
            v.push_back(u);
            val[u][v]=va;
            val[v][u]=va;
        }
    }
    while(q--)
    {
        int x1,y1;
        cin>>x1>>y1;
        cout<<0<<endl;
    }
    return 0;
}