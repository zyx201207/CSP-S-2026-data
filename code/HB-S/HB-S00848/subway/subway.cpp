#include<iostream>
using namespace std;
int c,n,m,d,q,w[500000],t[500000][500],x,y,z;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;++i)cin>>w[i];
    for(int i=0;i<n;++i){
        cin>>x;
        for(int j=0;j<x;++j){
            cin>>y>>z;
            t[y][x]=z;
        }
    }
    for(int i=0;i<q;++i){
        cin>>x>>y;
    }
    return 0;
}
