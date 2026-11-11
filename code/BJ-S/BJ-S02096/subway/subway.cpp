#include <bits/stdc++.h>
using namespace std;
long long m,n,d,q,a[500][5000],t[500][5000],w[500050],k[505],x[100005],y[100005];
long long tf[500005],tx[500][5000],tt[500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j];
            tf[a[i][j]]=i;
            tt[a[i][j]]=j;
            cin>>t[i][j];
            tx[i][j]=tx[i][j-1]+t[i][j];
        }
    }
    long long ans=0;
    for(int i=1;i<=q;i++)
    {
        cin>>x[i]>>y[i];
        ans+=w[x[i]]+w[y[i]];
        if(tf[x[i]]==tf[y[i]])
        {
            y[i]=max(x[i],y[i]);
            x[i]=min(x[i],y[i]);
            ans+=tx[tf[x[i]]][tt[y[i]]]-tx[tf[x[i]]][tt[x[i]]-1];
        }
    }
    cout<<ans;


    return 0;
}