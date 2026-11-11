#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[10000005];
int k[505];
int a[505][500005];
int t[505][500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }

    for(int i=1;i<=q;i++){
            int x,y;
        cin>>x>>y;

        cout<<w[x]+w[y]+t[i][x]+t[i][y];

    }
    return 0;
}
