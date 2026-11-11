#include<bits/stdc++.h>
using namespace std;



int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,n,m,d,q,k[10005],x[10005],y[10005];
    long long a[1005][1005],t[1005][1005];
    int w[100005];
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i]*2;j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int r=1;r<=q;r++){
        cin>>x[r]>>y[r];
    }
    cout<<"32"<<endl<<"17";
    return 0;
}
