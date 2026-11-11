#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int k[500005];
int a[100005][505];
int t[100005][505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int u,v,cu,cv;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i]*2;j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    int x,y;
    while(q--){
        cin>>x>>y;
        cout<<(w[x]+w[y])*2<<"\n";
    }
    return 0;
}
