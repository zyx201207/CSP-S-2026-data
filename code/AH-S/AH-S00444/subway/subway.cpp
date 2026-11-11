#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1,x;i<=n;i++){
        cin>>x;
        for(int j=1,a,b;j<=x;j++){
            cin>>a>>b;
        }
    }
    for(int i=1,x,y;i<=q;i++){
        cin>>x>>y;
        cout<<w[x]+w[y]<<endl;
    }
    return 0;
}
