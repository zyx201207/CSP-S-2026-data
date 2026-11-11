#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long c,n,m,d,q,w[N],f[N],t[N],cnt;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }for(int i=1;i<=n;i++){
        long long k,x;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>x>>t[i];
        }
    }
    while(q--){
        long long x,y;
        cin>>x>>y;
        cnt=0;
        cout<<w[x]+w[y]<<"\n";
    }
    return 0;
}
