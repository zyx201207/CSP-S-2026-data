#include <bits/stdc++.h>
using namespace std;
int ditie[505][500005];
int w[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,m,n,d,q;
    cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int zhan;
        cin>>zhan;
        for(int j=1;j<=zhan;j++){
            int a,t;
            cin>>a>>t;
            ditie[i][a]=t;
        }
    }
    return 0;
}
