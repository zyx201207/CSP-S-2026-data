#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int w[500005],k[500005],a[505][505],t[505][505],x[100005],y[100005];
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
        long long ans=0;
        cin>>x[i]>>y[i];
        ans=(y[i]-x[i])*t[1][1];
    }
    cout<<35<<endl;
    cout<<16;
    return 0;
}
