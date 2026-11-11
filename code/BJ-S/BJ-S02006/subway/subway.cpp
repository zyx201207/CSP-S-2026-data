#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
int c,n,m,d,q;
int k[520];
vector<int>vt[520];
int w[500500];
vector<int>mp[500500];
int g[520][520];
vector<int>v[520];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    memset(g,-1,sizeof(g))
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i]*2;j++)
        {
            int x;
            cin>>x;
            if(i&1) mp[x].push_back(i);
            else vt[i].push_back(x);
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<x*10+y*3<<endl;
    }
}
