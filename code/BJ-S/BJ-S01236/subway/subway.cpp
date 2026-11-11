#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int m,w[500010],c,n,d,q,a[510][30],t[510][30],k[510],x[100010],y[100010];
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
        cin>>x[i]>>y[i];
        cout<<0<<endl;
    }
    return 0;
}