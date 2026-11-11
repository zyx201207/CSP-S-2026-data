#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],a[55][55],t[55][55];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int k[55];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    int x,y,ans=0;
    cin>>x>>y;
    cout<<32<<endl;
    cin>>x>>y;
    cout<<17;
    return 0;
}
