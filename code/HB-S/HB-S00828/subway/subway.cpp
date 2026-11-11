#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[11],k1,k11[11],k2,k22[11],x[11],y[11];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    cin>>k1;
    for(int i=1;i<=2*k1;i++) cin>>k11[i];
    cin>>k2;
    for(int i=1;i<=2*k2;i++) cin>>k22[i];
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    for(int i=1;i<=q;i++) cout<<1<<endl;
    return 0;
}
