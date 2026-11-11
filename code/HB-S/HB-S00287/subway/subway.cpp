#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long a[500005];
int b[505][500005];
iny c[100005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*n;j++){
            cin>>b[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>c[i];
    }
    while(q--){
        cout<<c+n+m+d+q+a[q]<<endl;
    }
    return 0;
}
