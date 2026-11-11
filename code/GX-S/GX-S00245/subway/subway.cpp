#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[50005],k[505],a[505][50005]
,t[505][50005],z[50005][505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    while(q--){
        long long start,fish,ans;
        cin>>start>>fish;
        cout<<w[start];
    }
    return 0;
}
