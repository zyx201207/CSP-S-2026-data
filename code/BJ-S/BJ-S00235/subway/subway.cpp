#include<iostream>
#include<cstdio>
using namespace std;
int c,n,m,d,q,w[500005],k[505],a[505][500005],t[505][500005],x[100005],y[100005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
    }
    for(int i=1;i<=q;i++)cin>>x[i]>>y[i];
    for(int i=1;i<=q;i++){
        int ans=0;
        ans+=w[x[i]]+w[y[i]];
        for(int j=x[i];j<=y[i]-1;j++){
            ans+=t[1][1]+t[1][2];
        }
        cout<<ans<<"\n";
    }
    return 0;
}
