#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[20005],k,a[505][20005],t[505][20005],x[100005],y[100005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    cin>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
        cout<<w[x[i]]+t[min(n,2)][min(n,3)]+t[min(n,4)][min(n,5)]+t[min(n,6)][min(n,7)]+w[y[i]]<<endl;
    }
    return 0;
}
