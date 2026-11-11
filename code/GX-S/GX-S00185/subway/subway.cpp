#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway1.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q,w[100000000],k[100000000],a[100000000],t[100000000],x[100000],y[100000],ans;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i]){
            cin>>a[j]>>t[j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
        for(int j=x[i];j<=y[i];j++){
            ans+=w[x[i]];

        }
        ans+=w[y[i];
    }
    return 0;
}
