#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c;//not useful at all!
    int n,m,d,q,a[501][500001],k[501],w[500001],x,y;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;

    }
    return 0;
}
