#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e2+10;
const int M=5e5+10;
int c,n,m,d,q;
int w[M],k[N],a[N][M],t[N][M];

signed main(){

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        if(n==1){
            cout<<"0\n";
        }else{
            int ans=w[x]+w[y];
            ans+=t[x][x];
            ans+=t[x][y];
            cout<<ans<<"\n";
        }
    }

    return 0;
}
