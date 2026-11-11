#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],a[500005],t[500005],k[505],x[100005],y[100005];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i]){
            cin>>a[i];
            cin>>t[i];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i];
        cin>>y[i];
    }

    return 0;
}
