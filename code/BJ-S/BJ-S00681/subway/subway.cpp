#include<bits/stdc++.h>
using namespace std;
long c,n,m,d,q,a[1000100],w[10001000][520],b[10001000][510],k,t,ans,sum,x,y;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
            cin>>k;
        for(int j=1;j<=k;j++){
            cin>>w[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        ans+=w[x];
        sum+=w[y];
    }
    cout<<ans+sum;
    return 0;
}
