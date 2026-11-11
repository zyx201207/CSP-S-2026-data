#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[10005],r[2][10005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    for(int i=0;i<m*2+1;i++){
        int tes;
        cin>>tes;
    }
    for(int i=0;i<q;i++){
        cin>>r[0][i]>>r[1][i];
        cout<<r[0][i]<<r[1][i];
    }
}
