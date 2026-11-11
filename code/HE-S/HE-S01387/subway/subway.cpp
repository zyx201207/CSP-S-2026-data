#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,w[1000];

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int k[505],a[505][202],t[505][202];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    int x[1005],y[1005],g[5005]={};
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=q;i++){
        for(int j=x[i];j<=y[i];j++){
            g[i]+=w[j]+t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cout<<g[i]<<endl;
    }
    return 0;
}


