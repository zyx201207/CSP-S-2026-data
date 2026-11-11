#include<bits/stdc++.h>
using namespace std;
int w[505],k[505],a[505][500005],t[505][500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i){
        cin>>w[i];
    }
    for(int i=1;i<=n;++i){
        cin>>k[i];
        for(int j=1;j<=k[i];++j){
            cin>>a[i][j]>>t[i][j];

        }
    }
    for(int i=0;i<q;++i){
        int x,y;
        cin>>x>>y;
        long long sum=0;
        sum=w[x]+w[y]+t[x][x];
        sum+=t[x][y];
        cout<<sum<<"\n";
    }
    return 0;
}
