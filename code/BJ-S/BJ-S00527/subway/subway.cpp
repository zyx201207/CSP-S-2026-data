#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int v,w;
};
vector<node> bv[1500011];
int a[500011];
int lj[511][511];
const int oo=1145141919810;
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
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
            int lt,x;
            cin>>lt>>x;
            bv[lt].push_back({m+i,x});
            bv[m+i].push_back({lt,x});
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            lj[i][j]=oo;
        }
        lj[i][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(auto x:bv[m+i])
        {
            for(auto y:bv[x.v])if(y.v!=m+i)
            {
                lj[i][y.v-m]=lj[y.v-m][i]=x.w+y.w;
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                lj[i][j]=min(lj[i][j],lj[i][k]+lj[k][j]);
            }
        }
    }
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=1;j<=n;j++)
//        {
//            cout<<lj[i][j]<<" ";
//        }
//        cout<<"\n";
//    }
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        int ans=oo;
        for(auto x:bv[u])
        {
            for(auto y:bv[v])
            {
                //cout<<x.v<<" "<<y.v<<" "<<x.w<<" "<<y.w<<" ";
                ans=min(ans,lj[x.v-m][y.v-m]+x.w+y.w);
            }
        }
        cout<<ans+a[u]+a[v]<<"\n";
    }
    return 0;
}
