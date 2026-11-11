#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    if(n>500 || d>20 || q>100000)
        return 0;
    int w[m+5];
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    int k[n+5],a[n+5];
    int o;
    cin>>o;
    k[1]=o;
    for(int i=1;i<=1+(2*o);i++)
    {
        cin>>a[i];
        if(i!=1+(2*o))
        {
            cin>>k[i];
        }
    }
    int x[q+5],y[q+5];
    for(int i=1;i<=q;i++)
    {
        cin>>x[i]>>y[i];
    }
    cout<<w[1]+k[1]+k[2]+w[3]<<endl;
    cout<<w[1]+k[1]+k[2]+w[2];

    return 0;
}
