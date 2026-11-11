#include<bits/stdc++.h>
using namespace std;
long long b[1006],t[1006];
struct node{
    int v,w;
};
long long a[1006][1006];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,p,q;
    cin>>c>>n>>m>>p>>q;
    for (int i=1;i<=m;i++){
        cin>>b[i];
    }
    for (int i=1;i<=m;i++){
        for (int j=1;j<=m;j++){
            a[i][j]=4e18;
        }
    }
    for (int i=1;i<=m;i++){
        a[i][i]=0;
    }
    for (int i=1;i<=n;i++){
        int k;
        cin>>k;
        memset(t,0,sizeof t);
        vector<int> id;
        for (int j=1;j<=k;j++){
            int ai;
            cin>>ai;
            cin>>t[ai];
            id.push_back(ai);
            for (int vi:id){
                if (vi==ai) continue;
                a[ai][vi]=a[vi][ai]=min(a[ai][vi],t[ai]+t[vi]);
            }
        }
    }

    for (int k=1;k<=m;k++){
        for (int i=1;i<=m;i++){
            for (int j=1;j<=m;j++){
                if (i==j) continue;
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    while (q--){
        int x,y;
        cin>>x>>y;
        cout<<a[x][y]+b[x]+b[y]<<'\n';
    }
    return 0;
}
