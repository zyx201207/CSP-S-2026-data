#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,w[500005],x,y;
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    for(int i=0;i<q;i++){
        cin>>x>>y;
        int ans=0;
        cout<<(w[x]+w[y])*2;
    }
    return 0;
}
