#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,w[N],a[1001][1001],t[1001][1001];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(n==1){
        for(int i=1;i<=m;i++){
        cin>>w[i];
        }
        int x;
        cin>>x;
        for(int i=1;i<=x;i++){
            cin>>a[1][i]>>t[1][i];
        }
        for(int i=1;i<=q;i++){
            int y,z;
            cin>>y>>z;
            cout<<t[1][y]+t[1][z];
        }
    }else{
       for(int i=1;i<=m;i++){
        cin>>w[i];
       }
       for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>a[i][j]>>t[i][j];
            }
       }
       for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
       }
    }
   return 0;
}
