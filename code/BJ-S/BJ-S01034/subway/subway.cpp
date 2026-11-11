#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],k[510],a[510][500010],t[510][500010],x,y;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<10*x+8*y-1<<endl;
    }
    return 0;
}
