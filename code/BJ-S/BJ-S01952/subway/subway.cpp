#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500005],t[505][500005];
int a[505][500005],k[505];
void travel(int r){
    int x,y;
    long long ans;
    ans=w[x]+w[y];
    cout<<ans;
}
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
        travel(i);
    }
    return 0;
}
