#include<bits/stdc++.h>
using namespace std;
int w[500005];
int k[500005];
int b[505][500005];
int t[505][500005];
int mi[50];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=d;i++)
    {
        mi[i]=1e9;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>b[i][j]>>t[i][j];
            mi[b[i][j]]=min(mi[b[i][j]],t[i][j]);
        }
    }
    int x,y;
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y;
        cout<<w[x]+w[y]+mi[x]+mi[y]<<endl;
    }
    return 0;
}
