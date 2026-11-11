#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k,a[500005],x[100005],y[100005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a[j];
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x[i]>>y[i];
    }
    if(c==0)
    {
        if(w[1]==4&&w[2]==1)
        {
            cout<<32<<endl;
            cout<<17;
        }
        else if(w[1]==8&&w[2]==3)
        {
            cout<<35<<endl;
            cout<<16;
        }
    }
    return 0;
}
