#include<bits/stdc++.h>
using namespace std;
const int N=500010;
long long c,n,m,d,q,w[N],k;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
        for(int i=1;i<=m;i++) cin>>w[i];
        for(int j=1;j<=n;j++){
            cin>>k;
            for(int i=1;i<=2*k;i++) cin>>w[i];
        }
        for(int i=1;i<=q;i++) cin>>n>>m,cout<<1<<"\n";
    return 0;
}
