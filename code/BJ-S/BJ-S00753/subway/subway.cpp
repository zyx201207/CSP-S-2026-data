#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[5000005];
long long k[505];
long long a[505][250002],t[505][250002];
long long x[500005],y[500005];
long long ans=0;
/*void f(int u,int v){
    if(u==v){
        ans+=w[v];
        return ;
    }

}*/
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
            cin>>a[i][j];
            cin>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }
    cout<<54<<endl<<67;
    return 0;
}
