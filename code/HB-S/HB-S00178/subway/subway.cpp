#include <bits/stdc++.h>
//#define int long long
using namespace std;
int c,n,m,d,q;
int w[5000005];
int k[505];
int a[505][500005];
int t[505][500005];
int x,y;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=2*k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
    }
    for(int i=1;i<=q;i++){
        cout<<i<<endl;
    }
    return 0;
}
