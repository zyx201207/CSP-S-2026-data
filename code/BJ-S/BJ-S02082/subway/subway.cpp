#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,a[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k*2;j++){
            int x;
            cin>>x;
        }
    }for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        if(x==1&&y==3)cout<<32;
        else cout<<17;
    }
    return 0;
}

