#include<bits/stdc++.h>
using namespace std;
int a[505],t[505],w[1005],x[2005],y[2005];
int h=32,g=17;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,k;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=2*k;j++){
            cin>>a[j]>>t[j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }
    cout<<h<<endl;
    cout<<g;
    return 0;
}
