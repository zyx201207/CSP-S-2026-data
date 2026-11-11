#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c,d,t[2005][2005],w[200006],q;

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x;
            cin>>x;
            cin>>t[i][j];
        }
        
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]+t[x][y]+t[y][x]<<'\n';
    }
    return 0;
}