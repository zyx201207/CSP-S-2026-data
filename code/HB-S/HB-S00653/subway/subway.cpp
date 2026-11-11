#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[550000],k[550],a[550][550000],t[550][550000],x[110000],y[110000],r[110000];
int main(){
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
        cin>>x[i]>>y[i];
        r[i]+=w[x[i]]+w[y[i]];
    }
    return 0;
}
