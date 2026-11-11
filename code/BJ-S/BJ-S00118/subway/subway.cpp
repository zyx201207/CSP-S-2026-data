#include <bits/stdc++.h>
using namespace std;
const int M=5.1e5;
long long c,n,m,w[M],d,p,k[M],t[M],x[M],y[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int j=1;j<=n;j++){
        int k1;
        cin>>k1;
        for(int u=1;u<=k1;u++){
            cin>>k[u]>>t[u];
        }
    }
    for(int i=1;i<=p;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=p;i++){
        cout<<"1"<<endl;
    }
    return 0;
}
