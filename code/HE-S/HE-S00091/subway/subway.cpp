#include<bits/stdc++.h>
using namespace std;
int c,n,m,b,q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>b>>q;
    int k,x[n],y[n],t1[n];
    int w[m+5],a[50005][50005],t[50005][50005];
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int i=1;i<=k;i++){
            cin>>a[i][k]>>t[i][k];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=q;i++){

    }
    return 0;
}

