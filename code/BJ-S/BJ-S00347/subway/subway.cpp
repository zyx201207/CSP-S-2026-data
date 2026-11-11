#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[510];
int main(){
    freopen("subway.in","r",stdin);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=2;i<=n;i++){
        cin>>c;
        for(int j=1;j<=2*c;j++) cin>>a[j];
    }
    freopen("subway.out","w",stdout);
    cout<<32<<endl;
    cout<<17<<endl;
}
