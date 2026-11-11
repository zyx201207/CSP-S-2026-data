#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int c,m,n,d,q,k,x,y,w[500005];
int a[500005][500005],t[500005][500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);

    cin>>c>>m>>n>>d>>q;
    For(i,1,m)cin>>w[i];
    For(i,1,n){
        cin>>k;
        For(j,1,2*k)cin>>a[i][j]>>t[i][j];
    }
    while(q--){
        cin>>x>>y;
    }
    return 0;
}
