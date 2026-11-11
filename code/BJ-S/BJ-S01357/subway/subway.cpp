#include<bits/stdc++.h>
using namespace std;
int w[10000005],k[10000005],a[10000005],t[10000005],x[10000005],y[10000005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=1+2*k[i];j++)
        {
            cin>>a[j]>>t[j];
        }
    }
    for(int i=1;i<=q;i++)
        cin>>x[i]>>y[i];
    for(int i=1;i<=q;i++)
    {
        cout<<(w[i]*i/n+k[i]/2-1+q)*t[i]/a[i]<<endl;
    }
    return 0;
}
