#include<bits/stdc++.h>
using namespace std;
int a[200020];
int m[3050][3050],t[3050][3050],l,r,v[200200];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
       int o;
       cin>>o;
       for(int j=1;j<=o;j++){
            cin>>m[i][j]>>t[i][j];
       }

    }
    for(int i=1;i<=q;i++){
        cin>>l>>r;
        cout<<m[i][l]<<endl;
    }
    return 0;
}