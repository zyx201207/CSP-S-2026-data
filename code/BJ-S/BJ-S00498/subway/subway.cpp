#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],a[500005],k[500005],t[500005],x[500005],y[500005],sum;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=2*k[i];j++){
            cin>>a[i]>>t[i];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
        sum=w[x[i]]+w[y[i]];
    }
    cout<<sum;
    return 0;
}
