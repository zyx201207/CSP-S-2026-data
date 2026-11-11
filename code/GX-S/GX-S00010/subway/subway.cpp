#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,w[500005],ans=0;
    unordered_map<int,int>a[505];
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            a[i][x]=y;
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        for(int j=x;j<=y;j++){
            int mn=1e9;
            for(int k=1;k<=n;k++){
                ans+=a[k][j];
                break;
            }
        }
        ans+=w[x]+w[y];
        cout<<ans<<"\n";
    }
    return 0;
}
